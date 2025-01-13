/**
*
* Solution to homework assignment 1
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

int main() {

	int tabs = 0;
	double salary;

	cin >> tabs;
	cin >> salary;

	if (tabs <= 0 || salary <= 0) {
		cout << -1 << endl;

		return -1;
	}

	for (int i = 0; i < tabs; i++) {
		char site = '0';
		cin >> site;


		if (site == 'D' || site == 'd') {
			continue;
		}
		else if (site == 'F' || site == 'f') {
			salary -= 150;
		}
		else if (site == 'I' || site == 'i') {
			salary -= 100;
		}
		else if (site == 'R' || site == 'r') {
			salary -= 50;
		}
		else {
			cout << -1 << endl;

			return -1;
		}

		if (salary <= 0) {
			break;
		}
	}

	if (salary > 0) {
		cout << salary << endl;
	}
	else {
		cout << "You have lost your salary." << endl;
	}

	return 0;
}