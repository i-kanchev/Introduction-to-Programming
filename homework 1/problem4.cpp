/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Ivailo Kanchev
* @idnumber 2MI0600066
* @task 4
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main() {

	const double magicValue = 0.000001;

	double x = 0;
	double y = 0;

	cin >> x;
	cin >> y;

	double modX = x;
	if (modX < 0.0) {
		modX = -modX;
	}
	double modY = y;
	if (modY < 0.0) {
		modY = -modY;
	}

	double distanceCenter = (modX * modX) + (modY * modY);
	double distancePositiveTwo = ((x - 2) * (x - 2) + modY * modY);
	double distanceNegativeTwo = ((x + 2) * (x + 2) + modY * modY);

	if (modX > 4.0 || modY > 4.0) {
		cout << "Outside" << endl;
	}
	else if (modX == 4.0 || modY == 4.0) {
		cout << "Undefined" << endl;
	}

	else if (distanceCenter > 16.0) {
		cout << "White" << endl;
	}
	else if (16.0 - distanceCenter < magicValue && distanceCenter - 16.0 < magicValue) {
		cout << "Undefined" << endl;
	}

	else if (distancePositiveTwo < 1.0) {
		cout << "Black" << endl;
	}
	else if (1.0 - distancePositiveTwo < magicValue && distancePositiveTwo - 1.0 < magicValue) {
		cout << "Undefined" << endl;
	}
	else if (distancePositiveTwo < 4.0) {
		cout << "White" << endl;
	}
	else if (4.0 - distancePositiveTwo < magicValue && distancePositiveTwo - 4.0 < magicValue && y < 0.0) {
		cout << "Undefined" << endl;
	}

	else if (distanceNegativeTwo < 1.0) {
		cout << "White" << endl;
	}
	else if (1.0 - distanceNegativeTwo < magicValue && distanceNegativeTwo - 1.0 < magicValue) {
		cout << "Undefined" << endl;
	}
	else if (distanceNegativeTwo < 4.0) {
		cout << "Black" << endl;
	}
	else if (4.0 - distanceNegativeTwo < magicValue && distanceNegativeTwo - 4.0 < magicValue && y > 0.0) {
		cout << "Undefined" << endl;
	}

	else if (y > 0.0) {
		cout << "White" << endl;
	}
	else if (y < 0.0) {
		cout << "Black" << endl;
	}

	return 0;
}