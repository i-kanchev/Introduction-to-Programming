/**
*
* Solution to homework assignment 1
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

int main() {

	bool firstWinner = true;
	int number = 0;

	cin >> number;

	if (number <= 0) {
		cout << -1 << endl;

		return -1;
	}

	int digitCount = 0;
	int temporaryNumber = number;

	while (temporaryNumber != 0) {
		temporaryNumber /= 10;
		digitCount++;
	}

	int firstDigitCounter = digitCount;
	int lastDigitCounter = 1;

	while (firstDigitCounter >= lastDigitCounter) {
		if (firstDigitCounter == lastDigitCounter) {
			temporaryNumber = number;

			for (int i = 1; i < firstDigitCounter; i++) {
				temporaryNumber /= 10;
			}
			cout << temporaryNumber % 10;

			break;
		}
		else {
			int firstDigit = 0;
			int lastDigit = 0;

			temporaryNumber = number;

			for (int i = 1; i < lastDigitCounter; i++) {
				temporaryNumber /= 10;
			}

			lastDigit = temporaryNumber % 10;
			lastDigitCounter++;

			temporaryNumber = number;

			for (int i = 1; i < firstDigitCounter; i++) {
				temporaryNumber /= 10;
			}

			firstDigit = temporaryNumber % 10;
			firstDigitCounter--;

			if (firstDigit > lastDigit) {
				if (!firstWinner) {
					cout << " " << firstDigit;
				}
				else {
					cout << firstDigit;
					firstWinner = false;
				}
			}
			else if (firstDigit < lastDigit) {
				if (!firstWinner) {
					cout << " " << lastDigit;
				}
				else {
					cout << lastDigit;
					firstWinner = false;
				}
			}
		}
	}

	cout << endl;

	return 0;
}