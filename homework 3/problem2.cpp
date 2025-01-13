/**
*
* Solution to homework assignment 3
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

int const MIN_SIZE = 2;
int const MAX_SIZE = 100;

int longestDist(const int arr[], const int arrSize) {
	int position = -1;
	int distance = 0;

	for (int i = 0; i < arrSize; i++) {
		for (int j = i + distance + 1; j < arrSize; j++) {
			if (arr[i] == arr[j]) {
				distance = j - i;
				position = i;
			}
		}
	}

	return position;
}

int main() {
	int arrSize = 0;
	int arr[MAX_SIZE - 1];

	cin >> arrSize;

	if (arrSize < MIN_SIZE || arrSize > MAX_SIZE) {
		cout << -2 << endl;
		return 1;
	}

	for (int i = 0; i < arrSize; i++) {
		cin >> arr[i];
	}

	int position = longestDist(arr, arrSize);

	cout << position << endl;

	return 0;
}