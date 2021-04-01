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
#include <vector>
using namespace std;

int main();
int calcMean(int studentAbility, int subjectDifficulty);
string calcOverallMark(int studentMark);

enum Constants {
	FIFTY = 50,
	SIXTY_FOUR = 64,
	SIXTY_FIVE = 65,
	EIGHTY_FIVE = 85
};

struct Subject {
private:
	string name;
	int difficulty;
	int variability;
public:
	// Mutators
	void setSubjectName(string n) {
		name = n;
	}
	void setSubjectDifficulty(int diff) {
		difficulty = diff;
	}
	void setSubjectVariability(int vari) {
		variability = vari;
	}
	// Accessors
	string getSubjectName() {
		return name;
	}
	int getSubjectDifficulty() {
		return difficulty;
	}
	int getSubjectVariability() {
		return variability;
	}
};

struct Student {
private:
	string name, programName;
	int studentID;
	int ability;
	int consistency;
	vector<int> subjectsList;
public:
	// Mutators
	void setStudentName(string n) {
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
	void setStudentProgram(string progn) {
		programName = progn;
	}
	void setStudentSubjects(vector<int> subj) {
		subjectsList = subj;
	}
	// Accessors
	string getStudentName() {
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
	vector<int> getStudentSubjects() {
		return subjectsList;
	}
};
