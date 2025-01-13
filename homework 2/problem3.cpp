/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Ivailo Kanchev
* @idnumber 2MI0600066
* @task 3
* @compiler VC
*
*/

#include <iostream>

using namespace std;

void findNumberOfOperations(int firstNumber, int secondNumber) {
	int operationsCount = 0;

	while (firstNumber != secondNumber) {
		if (secondNumber < firstNumber) {
			secondNumber++;
		}
		else if (secondNumber % 2 != 0) {
			secondNumber++;
		}
		else {
			secondNumber /= 2;
		}

		operationsCount++;
	}

	cout << operationsCount << endl;
}


int main() {
	int initialNumber;
	int result;

	cin >> initialNumber;
	cin >> result;

	if (initialNumber <= 0) {
		cout << -1;
		return -1;
	}

	findNumberOfOperations(initialNumber, result);

	return 0;
}