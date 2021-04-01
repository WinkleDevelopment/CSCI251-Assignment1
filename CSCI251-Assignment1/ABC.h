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

using namespace std;

int main();
int calcMean(int studentAbility, int subjectDifficulty);
int calcStdDeviation(int studentConsistency, int subjectVariability);
int calcOverallMark(int mean, int stdDeviation);
string calcGrade(int studentMark);

enum Constants {
	FIFTY = 50,
	SIXTY_FOUR = 64,
	SIXTY_FIVE = 65,
	EIGHTY_FIVE = 85
};

class Subject {
public:
	std::string name;
	int difficulty;
	int variability;
	Subject(std::string name = "NULL", int difficulty = 0, int variability = 0) {
		this->name = name;
		this->difficulty = difficulty;
		this->variability = variability;
	}
	// Mutators
	void setSubjectName(std::string n) {
		name = n;
	}
	void setSubjectDifficulty(int diff) {
		difficulty = diff;
	}
	void setSubjectVariability(int vari) {
		variability = vari;
	}
	// Accessors
	std::string getSubjectName() {
		return name;
	}
	int getSubjectDifficulty() {
		return difficulty;
	}
	int getSubjectVariability() {
		return variability;
	}
	std::string toString() {
		return "Subject Name: " + name + "\nDifficulty: " + std::to_string(difficulty) + "\nVariability: " + std::to_string(variability) + "\n\n";
	}
};

struct Student {
public:
	std::string name, programName;
	int studentID;
	int ability;
	int consistency;
	vector<int> subjectsList;



	// Mutators
	void setStudentName(std::string n) {
		name = n;
	}
	void setStudentID(int id) {
		studentID = id;
	}
	void setStudentAbility(int ab) {
		ability = ab;
	}
	void setStudentConsistency(int con) {
		consistency = con;
	}
	void setStudentProgram(std::string progn) {
		programName = progn;
	}
	void setStudentSubjects(std::vector<int> subj) {
		subjectsList = subj;
	}
	// Accessors
	std::string getStudentName() {
		return name;
	}
	int getStudentID() {
		return studentID;
	}
	int getStudentAbility() {
		return ability;
	}
	int getStudentConsistency() {
		return consistency;
	}
	std::vector<int> getStudentSubjects() {
		return subjectsList;
	}
	std::string toString() const {
		return "Student Name: " + name + "\nStudent ID: " + std::to_string(studentID) + "\nStudent Ability: " + std::to_string(ability) + "\nStudent Consistency: " + std::to_string(consistency) + "\nProgram Name: " + programName + "\n";
	}
};

std::vector<Student> createStudents();
void createSubjects();