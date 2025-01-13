/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Ivailo Kanchev
* @idnumber 2MI0600066
* @task 2
* @compiler VC
*
*/

#include <iostream>

using namespace std;

const int SIZE_TEXT = 4096;
const int SIZE_STR = 1024;

int difference(const char* const str1, const char* const str2) {
	int counterStr1 = 0;
	int counterStr2 = 0;

	while (str1[counterStr1] != '\0') {
		counterStr1++;
	}

	while (str2[counterStr2] != '\0') {
		counterStr2++;
	}

	return (counterStr1 - counterStr2);
}

bool checkMatch(const char* text, const char* const str1, int position) {
	int counter = 0;

	while (str1[counter] != '\0') {
		if (str1[counter] != text[position]) {
			return false;
		}

		counter++;
		position++;
	}

	return true;
}

void applyChange(char* text, const char* const str1, const char* const str2, int pointOfInterest, const int sizeDifference) {
	char* tempText = new char[SIZE_TEXT];
	int counter = 0;

	if (sizeDifference > 0) {
		int tempCounter = 0;
		while (text[counter] != '\0') {
			if (counter == pointOfInterest) {
				counter += sizeDifference;
			}
			tempText[tempCounter] = text[counter];
			counter++;
			tempCounter++;
		}
		tempText[tempCounter] = '\0';
	}
	else if (sizeDifference < 0) {
		int tempCounter = 0;
		while (text[counter] != '\0') {
			if (counter == pointOfInterest) {
				tempCounter -= sizeDifference;
			}
			tempText[tempCounter] = text[counter];
			counter++;
			tempCounter++;
		}
		tempText[tempCounter] = '\0';
	}
	else {
		while (text[counter] != '\0') {
			tempText[counter] = text[counter];
			counter++;
		}
		tempText[counter] = '\0';
	}

	counter = 0;

	while (str2[counter] != '\0') {
		tempText[pointOfInterest] = str2[counter];
		counter++;
		pointOfInterest++;
	}

	counter = 0;

	while (tempText[counter] != '\0') {
		text[counter] = tempText[counter];
		counter++;
	}
	text[counter] = '\0';

	delete[] tempText;
}

int replace(char* text, const char* const str1, const char* const str2) {
	int replacements = 0;
	int counter = 0;
	int pointOfInterest = 0;
	int sizeDifference = difference(str1, str2);


	while (text[counter] != '\0') {
		if (text[counter] == str1[0]) {
			pointOfInterest = counter;
			if (checkMatch(text, str1, pointOfInterest)) {
				applyChange(text, str1, str2, pointOfInterest, sizeDifference);
				counter -= sizeDifference;
				replacements++;
			}
		}
		counter++;
	}

	return replacements;
}

void print(char* text) {
	int counter = 0;

	while (text[counter] != '\0') {
		cout << text[counter];
		counter++;
	}

	cout << endl;
}

int main() {
	char* text = new char[SIZE_TEXT];
	char* str1 = new char[SIZE_STR];
	char* str2 = new char[SIZE_STR];

	cin.getline(text, SIZE_TEXT);
	cin.getline(str1, SIZE_STR);
	cin.getline(str2, SIZE_STR);

	if (text[0] == '\0' || str1[0] == '\0') {
		cout << -3;

		delete[] text;
		delete[] str1;
		delete[] str2;

		return 1;
	}

	int replaces = replace(text, str1, str2);

	cout << replaces << endl;
	print(text);

	delete[] text;
	delete[] str1;
	delete[] str2;

	return 0;
}