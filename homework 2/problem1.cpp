/**
*
* Solution to homework assignment 2
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

long long const LOWER_LIMIT = 0;
long long const UPPER_LIMIT = 4294967295;

bool hasAlternatingBits(unsigned n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 1;
	}

	while (n != 0) {
		unsigned nCopy = n;
		n /= 2;

		if (nCopy % 2 == n % 2) {
			return 0;
		}
	}

	return 1;
}

int main() {
	long long number;
	cin >> number;

	if (number < LOWER_LIMIT || number > UPPER_LIMIT) {
		cout << -1;
		return -1;
	}

	if (hasAlternatingBits(number)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}