/**
*
* Solution to homework assignment 3
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

const char A_LOWER_LIMIT = 35;
const char A_UPPER_LIMIT = 55;
const char B_LOWER_LIMIT = 64;
const char B_UPPER_LIMIT = 96;

void generatePasswords(int a, int b, int maxNumberOfPasswords) {
	char A = A_LOWER_LIMIT;
	char B = B_LOWER_LIMIT;

	int x = 1;
	int y = 1;

	while (maxNumberOfPasswords > 0 && x <= a) {
		cout << A << B << x << y << B << A << '|';

		A++;
		if (A > A_UPPER_LIMIT) {
			A = A_LOWER_LIMIT;
		}
		B++;
		if (B > B_UPPER_LIMIT) {
			B = B_LOWER_LIMIT;
		}
		y++;
		if (y > b) {
			y = 1;
			x++;
		}

		maxNumberOfPasswords--;
	}
	cout << endl;
}

int main() {
	int a = 0;
	int b = 0;
	int maxNumberOfPasswords = 0;

	cin >> a;
	cin >> b;
	cin >> maxNumberOfPasswords;

	generatePasswords(a, b, maxNumberOfPasswords);

	return 0;
}