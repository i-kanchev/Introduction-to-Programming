// Ivailo Kanchev 2MI0600066

#include <iostream>

using namespace std;

const int SUDOKU_MIN_DIM = 3;
const int SUDOKU_MAX_DIM = 10;

bool isSudoku(int matrix[][SUDOKU_MAX_DIM], int dim) {
	bool numbers[SUDOKU_MAX_DIM * SUDOKU_MAX_DIM];
	for (int i = 0; i < SUDOKU_MAX_DIM * SUDOKU_MAX_DIM; i++) {
		numbers[i] = 1;
	}

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (matrix[i][j] < 1 || matrix[i][j] > dim * dim) {
				return 0;
			}
			if (numbers[matrix[i][j] - 1] == 0) {
				return 0;
			}
			else {
				numbers[matrix[i][j] - 1] = 0;
			}
		}
	}

	return 1;
}

int main() {
	int dim = 0;
	int matrix[SUDOKU_MAX_DIM][SUDOKU_MAX_DIM];

	cin >> dim;

	if (dim < SUDOKU_MIN_DIM || dim > SUDOKU_MAX_DIM) {
		cout << -1 << endl;

		return 1;
	}

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cin >> matrix[i][j];
		}
	}

	if (isSudoku(matrix, dim)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}