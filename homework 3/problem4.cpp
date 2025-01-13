/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Ivailo Kanchev
* @idnumber 2MI0600066
* @task 4
* @compiler VC
*
*/

#include <iostream>

using namespace std;

const int STRING_MAX_LENGTH = 100;

bool hasSymbol(const char str[], char symbol) {
	int counter = 0;

	while (str[counter] != '\0') {
		if (str[counter] == symbol) {
			return 1;
		}
		counter++;
	}

	return 0;
}

int longestSubstrWithUniqueSymbolsLength(const char str[]) {
	char uniqueStr[STRING_MAX_LENGTH];
	int uniqueLength = 0;
	int length = 0;
	int counter = 0;

	while (str[counter] != '\0') {
		if (hasSymbol(uniqueStr, str[counter])) {
			if (length > uniqueLength) {
				uniqueLength = length;
			}

			for (int i = 0; i < length - 1; i++) {
				uniqueStr[i] = uniqueStr[i + 1];
			}

			length--;
			uniqueStr[length] = '\0';
		}
		else {
			uniqueStr[length] = str[counter];
			length++;
			counter++;
		}
	}

	if (length > uniqueLength) {
		uniqueLength = length;
	}

	return uniqueLength;
}

int main() {
	char str[STRING_MAX_LENGTH];

	cin.getline(str, STRING_MAX_LENGTH);

	int uniqueLength = longestSubstrWithUniqueSymbolsLength(str);

	cout << uniqueLength << endl;

	return 0;
}