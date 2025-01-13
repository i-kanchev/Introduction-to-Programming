/**
*
* Solution to homework assignment 4
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

const int MIN_SIZE = 3;
const int MAX_SIZE = 1000;

int getPattern(int* numbers) {
	if (numbers[1] > numbers[0] && numbers[1] > numbers[2]) {
		return 1;
	}
	if (numbers[1] < numbers[0] && numbers[1] < numbers[2]) {
		return 2;
	}

	return 0;
}

bool hacksaw(int* numbers, int size, int position, int pattern) {
	if (position == size - 1) {
		return true;
	}

	if (pattern == 1) {
		if (numbers[position] < numbers[position - 1] || numbers[position] < numbers[position + 1]) {
			return false;
		}
		pattern = 2;
	}
	else {
		if (numbers[position] > numbers[position - 1] || numbers[position] > numbers[position + 1]) {
			return false;
		}
		pattern = 1;
	}

	return hacksaw(numbers, size, position + 1, pattern);
}

int main() {
	int size;

	cin >> size;

	if (size < MIN_SIZE || size > MAX_SIZE) {
		cout << -1 << endl;
		return 1;
	}

	int* numbers = new int[size];

	for (int i = 0; i < size; i++) {
		cin >> numbers[i];
	}

	int pattern = getPattern(numbers);

	if (pattern == 0) {
		cout << "no" << endl;

		delete[] numbers;

		return 0;
	}

	if (hacksaw(numbers, size, 1, pattern)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	delete[] numbers;

	return 0;
}