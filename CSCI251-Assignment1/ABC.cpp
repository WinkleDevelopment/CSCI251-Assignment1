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
    //Subject subjects[10];

    if (subjectFile.is_open()) {

        std::cout << "  ---Started Reading from Subject File---  " << endl;

        while (getline(subjectFile, line))
        {
            std::istringstream iss(line);

            //A new student data member is created
            Subject tempSubject;

            //getline(iss, tempSubject.name, ',');
            getline(iss, tempSubject.name, ',');


            getline(iss, str, ',');
            tempSubject.difficulty = stoi(str);

            getline(iss, str, ',');
            tempSubject.variability = stoi(str);

            //The new struct data member is added to the vector and returned for further use.
            //subjectList.push_back(std::move(tempSubject));

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

int calcMean(int studentAbility, int subjectDifficulty) {
    return ((studentAbility)-(subjectDifficulty));
}

int calcStdDeviation(int studentConsistency, int subjectVariability) {
    return ((studentConsistency)+(subjectVariability));
}

int calcOverallMark(int mean, int stdDeviation) {
    return mean + stdDeviation * 100;
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

int main() {

    createSubjects();
	vector<Student> students = createStudents();

	cout << endl << endl;
	cout << "Students: " << endl;

	for (Student student : students) {
        cout << student.toString();
        cout << "";


		cout << "Subjects:" << endl << endl;
		
		for (int x : student.getStudentSubjects()) {
            cout << subjects[x].toString();
		}

	}

	return 0;

}
