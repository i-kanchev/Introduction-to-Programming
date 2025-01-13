/**
*
* Solution to homework assignment 4
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

const int SIZE = 6;

bool isCorrect(char* equation) {
	if (!(equation[0] >= '0' && equation[0] <= '9')) {
		return false;
	}
	if (!(equation[1] == '+' || equation[1] == '-')) {
		return false;
	}
	if (!(equation[2] >= '0' && equation[2] <= '9')) {
		return false;
	}
	if (equation[3] != '=') {
		return false;
	}
	if (!(equation[4] >= '0' && equation[4] <= '9')) {
		return false;
	}

	return true;
}

bool isEqual(char* equation) {
	int firstNumber = equation[0] - '0';
	int secondNumber = equation[2] - '0';
	int thirdNumber = equation[4] - '0';

	switch (equation[1]) {
	case '+':
		if (thirdNumber == firstNumber + secondNumber) {
			return true;
		}
		break;
	case '-':
		if (thirdNumber == firstNumber - secondNumber) {
			return true;
		}
		break;
	}

	return false;
}

void printMatches(char* equation) {
	for (int i = 0; i < SIZE - 1; i++) {
		cout << equation[i];
	}
	cout << endl;
}

//value -> 5 - self-rotation, 2 - give, 3 - get => 1 action -> 5
void rearrangeMatches(char* equation, int positon, int value, bool& solution) {
	if (value > 5 || value == 4) {
		return;
	}

	if (positon == 6) {
		switch (equation[1]) {
		case '+':
			//equation[1] = '+';
			rearrangeMatches(equation, positon + 2, value, solution);
			equation[1] = '-';
			rearrangeMatches(equation, positon + 2, value + 3, solution);
			equation[1] = '+';
			break;
		case '-':
			equation[1] = '+';
			rearrangeMatches(equation, positon + 2, value + 2, solution);
			equation[1] = '-';
			rearrangeMatches(equation, positon + 2, value, solution);
			equation[1] = '-';
			break;
		}
		return;
	}

	if (positon == 8) {
		if (value == 5 && isEqual(equation)) {
			solution = true;
			printMatches(equation);
		}
		return;
	}

	switch (equation[positon]) {
	case '0':
		//equation[positon] = '0';
		rearrangeMatches(equation, positon + 2, value, solution);
		equation[positon] = '6';
		rearrangeMatches(equation, positon + 2, value + 5, solution);
		equation[positon] = '8';
		rearrangeMatches(equation, positon + 2, value + 2, solution);
		equation[positon] = '9';
		rearrangeMatches(equation, positon + 2, value + 5, solution);
		equation[positon] = '0';
		break;
	case '1':
		//equation[positon] = '1';
		rearrangeMatches(equation, positon + 2, value, solution);
		equation[positon] = '7';
		rearrangeMatches(equation, positon + 2, value + 5, solution);
		equation[positon] = '1';
		break;
	case '2':
		//equation[positon] = '2';
		rearrangeMatches(equation, positon + 2, value, solution);
		equation[positon] = '3';
		rearrangeMatches(equation, positon + 2, value + 5, solution);
		equation[positon] = '2';
		break;
	case '3':
		equation[positon] = '2';
		rearrangeMatches(equation, positon + 2, value + 5, solution);
		equation[positon] = '3';
		rearrangeMatches(equation, positon + 2, value, solution);
		equation[positon] = '5';
		rearrangeMatches(equation, positon + 2, value + 5, solution);
		equation[positon] = '9';
		rearrangeMatches(equation, positon + 2, value + 2, solution);
		equation[positon] = '3';
		break;
	case '4':
		//equation[positon] = '4';
		rearrangeMatches(equation, positon + 2, value, solution);
		//equation[positon] = '4';
		break;
	case '5':
		equation[positon] = '3';
		rearrangeMatches(equation, positon + 2, value + 5, solution);
		equation[positon] = '5';
		rearrangeMatches(equation, positon + 2, value, solution);
		equation[positon] = '6';
		rearrangeMatches(equation, positon + 2, value + 2, solution);
		equation[positon] = '9';
		rearrangeMatches(equation, positon + 2, value + 2, solution);
		equation[positon] = '5';
		break;
	case '6':
		equation[positon] = '0';
		rearrangeMatches(equation, positon + 5, value + 5, solution);
		equation[positon] = '5';
		rearrangeMatches(equation, positon + 2, value + 3, solution);
		equation[positon] = '6';
		rearrangeMatches(equation, positon + 2, value, solution);
		equation[positon] = '8';
		rearrangeMatches(equation, positon + 2, value + 2, solution);
		equation[positon] = '9';
		rearrangeMatches(equation, positon + 2, value + 5, solution);
		equation[positon] = '6';
		break;
	case '7':
		equation[positon] = '1';
		rearrangeMatches(equation, positon + 2, value + 3, solution);
		equation[positon] = '7';
		rearrangeMatches(equation, positon + 2, value, solution);
		//equation[positon] = '7';
		break;
	case '8':
		equation[positon] = '0';
		rearrangeMatches(equation, positon + 2, value + 3, solution);
		equation[positon] = '6';
		rearrangeMatches(equation, positon + 2, value + 3, solution);
		equation[positon] = '8';
		rearrangeMatches(equation, positon + 2, value, solution);
		equation[positon] = '9';
		rearrangeMatches(equation, positon + 2, value + 3, solution);
		equation[positon] = '8';
		break;
	case '9':
		equation[positon] = '0';
		rearrangeMatches(equation, positon + 2, value + 5, solution);
		equation[positon] = '3';
		rearrangeMatches(equation, positon + 2, value + 3, solution);
		equation[positon] = '5';
		rearrangeMatches(equation, positon + 2, value + 3, solution);
		equation[positon] = '6';
		rearrangeMatches(equation, positon + 2, value + 5, solution);
		equation[positon] = '8';
		rearrangeMatches(equation, positon + 2, value + 2, solution);
		equation[positon] = '9';
		rearrangeMatches(equation, positon + 2, value, solution);
		//equation[positon] = '9';
		break;
	}

}

bool rearrangeMatches(char* equation) {
	bool solution = false;

	rearrangeMatches(equation, 0, 0, solution);

	return solution;
}

int main() {
	char* equation = new char[SIZE];
	cin.getline(equation, SIZE);

	if (!isCorrect(equation)) {
		cout << -1 << endl;
		delete[] equation;
		return 1;
	}

	if (!rearrangeMatches(equation)) {
		cout << "No" << endl;
	}

	delete[] equation;

	return 0;
}