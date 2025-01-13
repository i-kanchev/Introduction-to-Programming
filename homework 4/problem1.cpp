/**
*
* Solution to homework assignment 4
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

const int DEFAULT_SIZE = 10;
const int CASE_DIFFERENCE = 'a' - 'A';

int getMaxPermutations(const char* str) {
	int maxPermutations = 1;

	int counter = 0;
	while (str[counter] != '\0') {
		if ((str[counter] >= 'a' && str[counter] <= 'z') || (str[counter] >= 'A' && str[counter] <= 'Z')) {
			maxPermutations *= 2;
		}
		counter++;
	}

	return maxPermutations;
}

void fillPermutations(char* str, char** permutations, int maxPermutations) {
	for (int i = 0; i < maxPermutations; i++) {
		int counter = 0;

		while (str[counter] != '\0') {
			permutations[i][counter] = str[counter];
			counter++;
		}

		permutations[i][counter] = '\0';
	}
}

void addPermutation(char* str, char** permutations, int consecutivePermutation) {
	int counter = 0;

	while (str[counter] != '\0') {
		permutations[consecutivePermutation][counter] = str[counter];
		counter++;
	}

	permutations[consecutivePermutation][counter] = '\0';
}

void applyPermutations(char* str, char** permutations, int& consecutivePermutation, int position) {
	if (str[position] != '\0') {
		if (!(str[position] >= 'a' && str[position] <= 'z') && !(str[position] >= 'A' && str[position] <= 'Z')) {
			applyPermutations(str, permutations, consecutivePermutation, position + 1);
		}
		else {
			if (!(str[position] >= 'a' && str[position] <= 'z')) {
				str[position] += CASE_DIFFERENCE;
			}
			applyPermutations(str, permutations, consecutivePermutation, position + 1);

			str[position] -= CASE_DIFFERENCE;
			applyPermutations(str, permutations, consecutivePermutation, position + 1);
		}
	}
	else {
		addPermutation(str, permutations, consecutivePermutation);
		consecutivePermutation++;
	}
}

char** letterCasePermutation(char* str) {
	int maxPermutations = getMaxPermutations(str);

	char** permutations = new char* [maxPermutations];
	for (int i = 0; i < maxPermutations; i++) {
		permutations[i] = new char[DEFAULT_SIZE];
	}

	fillPermutations(str, permutations, maxPermutations);

	int consecutivePermutation = 0;
	int position = 0;

	applyPermutations(str, permutations, consecutivePermutation, position);

	return permutations;
}

void printPermutation(char** permutations, int maxPermutations) {
	for (int i = 0; i < maxPermutations; i++) {
		int counter = 0;

		while (permutations[i][counter] != '\0') {
			cout << permutations[i][counter];
			counter++;
		}

		cout << ' ';
	}
	cout << endl;
}

int main() {
	char* str = new char[DEFAULT_SIZE];
	cin.getline(str, DEFAULT_SIZE);

	char** permutations = letterCasePermutation(str);

	int maxPermutations = getMaxPermutations(str);

	printPermutation(permutations, maxPermutations);

	for (int i = 0; i < maxPermutations; i++) {
		delete[] permutations[i];
	}
	delete[] permutations;
	delete[] str;

	return 0;
}