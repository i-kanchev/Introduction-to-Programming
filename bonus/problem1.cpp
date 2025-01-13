// Ivailo Kanchev 2MI0600066

#include <iostream>

using namespace std;

bool haveSameNumberDigits(int firstNumber, int secondNumber) {
	while (firstNumber != 0 && secondNumber != 0) {
		firstNumber /= 10;
		secondNumber /= 10;
	}

	if (firstNumber != secondNumber) {
		return 0;
	}

	return 1;
}

int myAbs(int number) {
	if (number < 0) {
		number = -number;
	}

	return number;
}

int numberDistance(int first, int second) {
	int totalDistance = 0;

	while (first != 0) {
		int distance = first % 10 - second % 10;
		totalDistance += myAbs(distance);
		first /= 10;
		second /= 10;
	}

	return totalDistance;
}

int main() {
	int firstNumber = 0;
	int secondNumber = 0;

	cin >> firstNumber;
	cin >> secondNumber;

	if (!haveSameNumberDigits(firstNumber, secondNumber)) {
		cout << -1 << endl;

		return 1;
	}

	int digitDistance = numberDistance(firstNumber, secondNumber);

	cout << digitDistance << endl;

	return 0;
}