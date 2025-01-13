/**
*
* Solution to homework assignment 2
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

long long const LOWER_LIMIT = 1;
long long const UPPER_LIMIT = 1000000000;

bool isPalindrome(long long number) {
	if (number / 100 == 0) {
		return 0;
	}

	long long tempNumber = number;
	long long reverseNumber = 0;

	while (tempNumber != 0) {
		reverseNumber = (10 * reverseNumber) + (tempNumber % 10);
		tempNumber /= 10;
	}

	if (number == reverseNumber) {
		return 1;
	}

	return 0;
}

long long findPalindrome(long long initialNumber) {
	long long decreasingNumber = initialNumber;
	long long increasingNumber = initialNumber;

	while (true) {
		if (isPalindrome(decreasingNumber)) {
			return decreasingNumber;
		}
		if (isPalindrome(increasingNumber)) {
			return increasingNumber;
		}

		decreasingNumber--;
		increasingNumber++;
	}
}

int main() {
	long long number;

	cin >> number;

	if (number < LOWER_LIMIT || number > UPPER_LIMIT) {
		cout << -1;
		return -1;
	}

	long long palindrome = findPalindrome(number);
	cout << palindrome << endl;

	return 0;
}