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
#include "main.h"

using namespace std;

int main() {

	Subject *testSubject = testSubject("Test Subject",1,2);

	Subject testlist = {*testSubject};

	//Student testStudent = Student("Test Name",123456,2,3,testlist);

	cout << "Student Name: " << testStudent.getStudentName() << endl;
	cout << "Student ID: " << testStudent.getStudentName() << endl;
	cout << "Student Ability: " << testStudent.getStudentName() << endl;
	cout << "Student Consistency: " << testStudent.getStudentName() << endl;
	cout << "Student Subjects: " << endl;
	/*for (auto subject : testList)
	{
		 cout << testStudent.getStudentName() << endl;
	}*/

	return 0;

}