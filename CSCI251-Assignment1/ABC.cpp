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
#include "ABC.h"
#include <vector>

using namespace std;

int main() {

	Subject TestObject;

	TestObject.setSubjectName("Test Name");

	cout << "Subject Name: " << TestObject.getSubjectName();
	cout << Constants::FIFTY;
	return 0;

}
