/*
* 
*	Bachelor of Computer Science (Software Engineering) 
*			
*				Kyle J. Brookes | 6822794
* 
*					 Assignment 1
* 
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "ABC.h"

using namespace std;

const int limit = 10;
Subject subjects[limit];

void createSubjects() {

    string fileName = "Subjects.txt";
    string line;
    string str;

    fstream subjectFile(fileName);

    int x = 0;

    if (subjectFile.is_open()) {

        std::cout << "  ---Started Reading from Subject File---  " << endl;

        while (getline(subjectFile, line))
        {
            std::istringstream iss(line);

            Subject tempSubject;

            getline(iss, tempSubject.name, ',');


            getline(iss, str, ',');
            tempSubject.difficulty = stoi(str);

            getline(iss, str, ',');
            tempSubject.variability = stoi(str);

            subjects[x] = tempSubject;
            x++;
        }

        std::cout << "  ---Finished Reading from Subject File---  " << endl;

    }
    subjectFile.close();
}

vector<Student> createStudents() {

    vector<Student> studentList;
    string fileName = "Students.txt";
    string line;
    string str;

    fstream studentFile(fileName);

    if (studentFile.is_open()) {

        std::cout << "  ---Started Reading from Student File---  " << endl;

        while (getline(studentFile, line))
        {
            std::istringstream iss(line);

            //A new student data member is created
            Student tempStudent;


            getline(iss, tempStudent.name, ',');

            //To convert the strings to an int, the string is given to a temporary variable
            //Then the temporary variable is parsed to an int using stoi and the code datamember from the struct is assign to that new int
            getline(iss, str, ',');
            tempStudent.studentID = stoi(str);

            getline(iss, str, ',');
            tempStudent.ability = stoi(str);

            getline(iss, str, ',');
            tempStudent.consistency = stoi(str);

            getline(iss, tempStudent.programName, ':');

            // push ints into subject list
            while (getline(iss, str, ',')) {
                tempStudent.subjectsList.push_back(stoi(str));
            }

            //The new struct data member is added to the vector and returned for further use.
            studentList.push_back(std::move(tempStudent));

        }

        std::cout << "  ---Finished Reading from Student File---  " << endl;

    }
    studentFile.close();

    return studentList;

}

double calcMean(int studentAbility, int subjectDifficulty) {
    return ((studentAbility)-(subjectDifficulty));
}

double calcStdDeviation(int studentConsistency, int subjectVariability) {
    return ((studentConsistency)+(subjectVariability));
}

int calcOverallMark(int mean, int stdDeviation) {
    return mean + stdDeviation;
}

string calcGrade(int studentMark) {
    if (studentMark < Constants::FIFTY) {
        return "Fail";
    }
    else if (studentMark >= Constants::FIFTY && studentMark <= Constants::SIXTY_FOUR) {
        return "Pass";
    }
    else if (studentMark >= Constants::SIXTY_FIVE && studentMark <= Constants::EIGHTY_FIVE) {
        return "Good";
    }
    else if (studentMark > Constants::EIGHTY_FIVE) {
        return "Very Good";
    }
}

void outputGrades() {

    createSubjects();
    vector<Student> students = createStudents();

    fstream OutputFile;
    OutputFile.open("Output.txt", ofstream::out | ofstream::trunc);
    if (OutputFile.is_open()) {

        for (Student student : students) {
            // Prints Student Details
            OutputFile << student.toString() << std::endl;;
            size_t cap = 0;
            for (int x : student.getStudentSubjects()) {

                auto var = 0;
                var = student.getStudentSubjects().size();
                cap = cap++;

                // Gets Mean and Standard Deviation
                double mean = calcMean(student.getStudentAbility(), subjects[x].getSubjectDifficulty());
                double standardDeviation = calcStdDeviation(student.getStudentConsistency(), subjects[x].getSubjectVariability());
                int cnut = 1;

                // Creates Random Number
                default_random_engine generator(time(0));
                normal_distribution<double> dist(mean, standardDeviation);
                int mark = round((int)dist(generator));

                while (cnut <= 3)
                {
                    OutputFile << "Subject: " << subjects[x].getSubjectName() << " " << x << "\nAttempt Number: " << cnut << "\nMark: " << mark << "\nStudent: " << student.getStudentName() << std::endl;

                    // Check if Grade is Passable
                    if (cnut == 3 && mark < 50) {

                        OutputFile << "Overall Grade: Fail" << std::endl;
                        OutputFile << "Exceeded the three attempt limit with an overall fail mark. The student has been excluded from college." << std::endl << std::endl;
                        vector<int> deleteStudent = {};
                        student.setStudentSubjects(deleteStudent);
                    }
                    else if (cnut <= 3 && mark >= 50) {
                        OutputFile << "Grade: " << calcGrade(mark) << std::endl << std::endl;
                        // Checks if its last subject for overall grade
                        if (student.getStudentSubjects().size() == cap) {
                            OutputFile << "Overall Grade: Pass" << std::endl << std::endl;
                        }
                        cnut = 99; // Passes and Stops Loop
                    }
                    else {
                        OutputFile << "Grade: Fail" << std::endl << std::endl;
                        mark = round(dist(generator)); // Resets Number
                    }
                    cnut++;
                }
             }
         } 
    } else {
        cout << "File doesn't exist!";
    }
}


int main() {

    outputGrades();
	return 0;

}
