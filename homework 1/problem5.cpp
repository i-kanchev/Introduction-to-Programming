/**
*
* Solution to homework assignment 1
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

int main() {

	int number = 0;

	cin >> number;

	if (number < 0) {
		cout << -1 << endl;

		return -1;
	}

	int numberWithOddDigits = 0;
	int position = 1;

	while (number != 0) {
		if (number % 2 == 1) {
			numberWithOddDigits = position * (number % 10) + numberWithOddDigits;
			position *= 10;
		}

		number /= 10;
	}

	cout << numberWithOddDigits << endl;

	return 0;
}