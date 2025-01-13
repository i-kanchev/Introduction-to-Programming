/**
*
* Solution to homework assignment 1
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

int main() {

	int n = 0;

	cin >> n;

	if (n <= 0 || n >= 10) {
		cout << -1 << endl;

		return -1;
	}

	for (int i = 1; i <= 2 * n - 1; i++) {
		if (i < n) {
			for (int j = 1; j <= n; j++) {
				if (j < i) {
					cout << " ";
				}
				else {
					cout << j;
				}
			}
			cout << endl;
		}
		else if (i == n) {
			for (int j = 1; j < n; j++) {
				cout << " ";
			}
			cout << i << endl;
		}
		else {
			for (int j = 1; j < n; j++) {
				cout << " ";
			}
			for (int j = n; j > 0; j--) {
				if (j > (2 * n - (i + 1))) {
					cout << j;
				}
			}
			cout << endl;
		}
	}

	return 0;
}