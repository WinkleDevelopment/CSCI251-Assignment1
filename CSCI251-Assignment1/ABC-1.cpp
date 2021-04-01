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
#include "ABC.h"

using namespace std;

int calcMean(int studentAbility, int subjectDifficulty) {
	return ((studentAbility) - (subjectDifficulty));
}

int calcStdDeviation(int studentConsistency, int subjectVariability) {
	return ((studentConsistency) + (subjectVariability));
}

string calcOverallMark(int studentMark) {
	if (studentMark < Constants::FIFTY) {
		return "Fail";
	} else if (studentMark >= Constants::FIFTY && studentMark <= Constants::SIXTY_FOUR) {
		return "Pass";
	} else if (studentMark >= Constants::SIXTY_FIVE && studentMark <= Constants::EIGHTY_FIVE) {
		return "Good";
	} else if (studentMark > Constants::EIGHTY_FIVE) {
		return "Very Good";
	}
}