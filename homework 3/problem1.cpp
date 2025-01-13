/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Ivailo Kanchev
* @idnumber 2MI0600066
* @task 1
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int const MIN_WORDS = 2;
int const MAX_WORDS = 50;
int const MAX_LETTERS = 20;

int getLength(const char word[]) {
	int counter = 0;
	while (word[counter] != '\0') {
		counter++;
	}

	return counter;
}

bool checkReplace(const char presentWord[], const char nextWord[]) {
	int replacements = 2;
	int counter = 0;
	while (presentWord[counter] != '\0' && replacements != 0) {
		if (presentWord[counter] != nextWord[counter]) {
			replacements--;
		}
		counter++;
	}

	return replacements;
}

bool checkRemove(const char presentWord[], const char nextWord[]) {
	bool letterRemoved = 0;
	int counter = 0;

	while (presentWord[counter] != '\0') {
		if (!letterRemoved) {
			if (presentWord[counter] != nextWord[counter]) {
				letterRemoved = 1;
			}
		}
		else {
			if (presentWord[counter] != nextWord[counter - 1]) {
				return 0;
			}
		}
		counter++;
	}

	return 1;
}

bool checkAdd(const char presentWord[], const char nextWord[]) {
	bool letterAdded = 0;
	int counter = 0;

	while (presentWord[counter] != '\0') {
		if (!letterAdded) {
			if (presentWord[counter] != nextWord[counter]) {
				letterAdded = 1;
			}
		}
		else {
			if (presentWord[counter] != nextWord[counter + 1]) {
				return 0;
			}
		}
		counter++;
	}

	return 1;
}

bool isCorrect(const char sequence[][MAX_LETTERS], int sequenceSize) {
	int presentWordCounter = getLength(sequence[0]);

	for (int i = 0; i < sequenceSize - 1; i++) {
		int nextWordCounter = getLength(sequence[i + 1]);

		if (presentWordCounter == nextWordCounter) {
			if (!checkReplace(sequence[i], sequence[i + 1])) {
				return 0;
			}
		}
		else if (presentWordCounter - nextWordCounter == 1) {
			if (!checkRemove(sequence[i], sequence[i + 1])) {
				return 0;
			}
		}
		else if (presentWordCounter - nextWordCounter == -1) {
			if (!checkAdd(sequence[i], sequence[i + 1])) {
				return 0;
			}
		}
		else {
			return 0;
		}

		presentWordCounter = nextWordCounter;
	}

	return 1;
}

int main() {
	int sequenceSize = 0;
	char sequence[MAX_WORDS][MAX_LETTERS];

	cin >> sequenceSize;
	cin.ignore();

	if (sequenceSize < MIN_WORDS || sequenceSize > MAX_WORDS) {
		cout << -1 << endl;
		return 1;
	}

	for (int i = 0; i < sequenceSize; i++) {
		cin.getline(sequence[i], MAX_LETTERS);
	}

	if (isCorrect(sequence, sequenceSize)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}