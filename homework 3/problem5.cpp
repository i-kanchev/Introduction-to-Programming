/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Ivailo Kanchev
* @idnumber 2MI0600066
* @task 5
* @compiler VC
*
*/

#include <iostream>

using namespace std;

const int STRING_MAX_LENGTH = 255;
const int caseDifference = 'a' - 'A';

bool isCorresponding(char text[]) {
	char lowerCaseString[STRING_MAX_LENGTH];
	char upperCaseString[STRING_MAX_LENGTH];

	int counter = 0;
	int lowerCounter = 0;
	int upperCounter = 0;

	while (text[counter] != '\0') {
		if (text[counter] >= 'A' && text[counter] <= 'Z') {
			upperCaseString[upperCounter] = text[counter];
			upperCounter++;
		}
		else if (text[counter] >= 'a' && text[counter] <= 'z') {
			lowerCaseString[lowerCounter] = text[counter];
			lowerCounter++;
		}
		counter++;
	}

	upperCaseString[upperCounter] = '\0';
	lowerCaseString[lowerCounter] = '\0';

	if (upperCounter != lowerCounter) {
		return 0;
	}

	counter = 0;

	while (upperCaseString[counter] != '\0') {
		if (upperCaseString[counter] + caseDifference != lowerCaseString[counter]) {
			return 0;
		}
		counter++;
	}

	return 1;
}

int main() {
	char text[STRING_MAX_LENGTH];

	cin.getline(text, STRING_MAX_LENGTH);

	if (isCorresponding(text)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}