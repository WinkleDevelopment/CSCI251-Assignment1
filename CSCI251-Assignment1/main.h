/*
*
*	Bachelor of Computer Science (Software Engineering)
*
*				Kyle J. Brookes | 6822794
*
*					 Assignment 1
*
*/

class Subject {
private:
	string name;
	int difficulty;
	int variability;
public:
	// Constructor
	Subject(string name, int difficulty, int variability) {
		this->name = name;
		this->difficulty = difficulty;
		this->variability = variability;
	}
	// Mutators
	void setSubjectName(string name) {
		this->name = name;
	}
	void setSubjectDifficulty(int difficulty) {
		this->difficulty = difficulty;
	}
	void setSubjectVariability(int variability) {
		this->variability = variability;
	}
	// Accessors
	string getSubjectName() {
		return this->name;
	}
	int getSubjectDifficulty() {
		return this->difficulty;
	}
	int getSubjectVariability() {
		return this->variability;
	}
};

class Student {
private:
	string name;
	int studentID;
	int ability;
	int consistency;
	Subject* subjects;
public:
	// Constructor
	Student(string name, int studentID, int ability, int consistency, Subject* subjects) {
		this->name = name;
		this->studentID = studentID;
		this->ability = ability;
		this->consistency = consistency;
		*this->subjects = *subjects;
	}
	// Mutators
	void setStudentName(string name) {
		this->name = name;
	}
	void setStudentID(int studentID) {
		this->studentID = studentID;
	}
	void setStudentAbility(int ability) {
		this->ability = ability;
	}
	void setStudentConsistency(int consistency) {
		this->consistency = consistency;
	}
	void setStudentSubjects(Subject* subjects) {
		*this->subjects = *subjects;
	}
	// Accessors
	string getStudentName() {
		return this->name;
	}
	int getStudentID() {
		return this->studentID;
	}
	int getStudentAbility() {
		return this->ability;
	}
	int getStudentConsistency() {
		return this->consistency;
	}
	Subject getStudentSubjects() {
		return *this->subjects;
	}
};

int main();