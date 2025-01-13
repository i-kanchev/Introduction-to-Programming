/**
*
* Solution to homework assignment 2
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

int const LOWER_LIMIT = 0;

int addDigit(int number, int digit, int& steps) {
	number = 10 * number + digit;
	steps++;

	return number;
}

int removeDigit(int number, int& steps) {
	number /= 10;
	steps++;

	return number;
}

int swapDigits(int number, int digit, int sortedDigits, int& steps) {
	int newNumber = number;
	int nextDigit = 0;
	double positionNext = 0.1;
	double positionDigit = 0.1;

	while (number != sortedDigits) {
		positionNext *= 10;
		nextDigit = number % 10;
		if (number % 10 == digit) {
			positionDigit = positionNext;
		}
		number /= 10;
	}

	newNumber += (int)positionNext * (-nextDigit + digit) + (int)positionDigit * (-digit + nextDigit);

	steps++;

	return newNumber;

}

int getNextDigit(int number, int sortedDigits) {
	int digit = 0;
	while (number != sortedDigits) {
		digit = number % 10;
		number /= 10;
	}

	return digit;
}

bool hasGivenDigit(int digit, int number, int sortedDigits) {
	while (number != sortedDigits) {
		if (number % 10 == digit) {
			return 1;
		}
		number /= 10;
	}

	return 0;
}

int increaseSortedDigits(int number, int sortedDigits) {
	int newDigit = 0;
	while (number != sortedDigits) {
		newDigit = number % 10;
		number /= 10;
	}

	sortedDigits = sortedDigits * 10 + newDigit;

	return sortedDigits;
}

int transform(int initialNumber, int finalNumber) {
	int steps = 0;
	int sortedDigits = 0;

	while (initialNumber != finalNumber) {
		int digit = getNextDigit(finalNumber, sortedDigits);
		int lastDigit = initialNumber % 10;

		if (finalNumber == sortedDigits) {
			initialNumber = removeDigit(initialNumber, steps);
		}
		else if (hasGivenDigit(digit, initialNumber, sortedDigits)) {
			if (digit == getNextDigit(initialNumber, sortedDigits)) {
				sortedDigits = increaseSortedDigits(initialNumber, sortedDigits);
			}
			else {
				initialNumber = swapDigits(initialNumber, digit, sortedDigits, steps);
				sortedDigits = increaseSortedDigits(initialNumber, sortedDigits);
			}
		}
		else if (initialNumber == sortedDigits) {
			initialNumber = addDigit(initialNumber, digit, steps);
		}
		else if (!hasGivenDigit(lastDigit, finalNumber, sortedDigits)) {
			initialNumber = removeDigit(initialNumber, steps);
		}
		else {
			initialNumber = addDigit(initialNumber, digit, steps);
		}
	}

	return steps;
}

int main() {
	int n = 0;
	int k = 0;

	cin >> n;
	cin >> k;

	if (n < LOWER_LIMIT || k < LOWER_LIMIT) {
		cout << -1;
		return -1;
	}

	int steps = transform(n, k);

	cout << steps << endl;

	return 0;
}