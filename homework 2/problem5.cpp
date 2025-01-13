/**
*
* Solution to homework assignment 2
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

bool isLeapYear(unsigned int year) {
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
		return 1;
	}

	return 0;
}

void getYear(unsigned long long& timeValue, unsigned int& year) {
	while ((!isLeapYear(year) && timeValue >= 365) || (isLeapYear(year) && timeValue >= 366)) {
		timeValue -= 365;
		if (isLeapYear(year)) {
			timeValue -= 1;
		}
		year++;
	}
}

void getMonth(unsigned long long& timeValue, unsigned int& month, unsigned int year) {
	while (true) {
		if (timeValue > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)) {
			timeValue -= 31;
			month++;
		}
		else if (timeValue > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
			timeValue -= 30;
			month++;
		}
		else if (timeValue > 28 && month == 2 && !isLeapYear(year)) {
			timeValue -= 28;
			month++;
		}
		else if (timeValue > 29 && month == 2 && isLeapYear(year)) {
			timeValue -= 29;
			month++;
		}
		else {
			break;
		}
	}
}

void getDay(unsigned long long& timeValue, unsigned int& day) {
	day += timeValue;
}

void getHours(unsigned long long& timeValue, unsigned int& hours) {
	hours = timeValue % 24;
	timeValue /= 24;
}

void getMinutes(unsigned long long& timeValue, unsigned int& minutes) {
	minutes = timeValue % 60;
	timeValue /= 60;
}

void getSeconds(unsigned long long& timeValue, unsigned int& seconds) {
	seconds = timeValue % 60;
	timeValue /= 60;
}

void printDate(unsigned long long timeValue) {
	unsigned int year = 1970;
	unsigned int month = 1;
	unsigned int day = 1;
	unsigned int hours = 0;
	unsigned int minutes = 0;
	unsigned int seconds = 0;

	getSeconds(timeValue, seconds);
	getMinutes(timeValue, minutes);
	getHours(timeValue, hours);

	getYear(timeValue, year);
	getMonth(timeValue, month, year);
	getDay(timeValue, day);

	if (day < 10) {
		cout << 0;
	}
	cout << day << ".";
	if (month < 10) {
		cout << 0;
	}
	cout << month << ".";
	cout << year << " ";
	if (hours < 10) {
		cout << 0;
	}
	cout << hours << ":";
	if (minutes < 10) {
		cout << 0;
	}
	cout << minutes << ":";
	if (seconds < 10) {
		cout << 0;
	}
	cout << seconds << endl;
}

int main() {
	unsigned long long timeValue;

	cin >> timeValue;

	printDate(timeValue);

	return 0;
}