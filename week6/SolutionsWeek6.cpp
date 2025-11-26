#include <iostream>
using namespace std;

const size_t MAX_SIZE = 50;

bool validateSize(int size) {
	return size > 0 && size <= MAX_SIZE;
}

//zad1
void printSumOfElementsInEachRow(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
	if (!validateSize(rows) || !validateSize(cols)) {
		cout << "Invalid size!" << endl;
		return;
	}

	int rowSum = 0;
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			rowSum += matrix[i][j];
		}
		cout << "Sum of row " << i << ": " << rowSum << endl;
		rowSum = 0;
	}
}

//zad2
void printDiagonals(int matrix[][MAX_SIZE], size_t size) {
	if (!validateSize(size)) {
		cout << "Invalid size!" << endl;
		return;
	}

	//primary (negative) diagonal
	for (size_t i = 0; i < size; i++) {
		cout << matrix[i][i] << " ";
	}
	cout << endl;

	//secondary (positive) diagonal
	for (size_t i = 0; i < size; i++) {
		cout << matrix[i][size - i - 1] << " ";
	}
	cout << endl;

}

//zad3 - laziest solution. Can you suggest a better one?
void printElementsOfMatrixWhoseIndexesSumUpToS(int matrix[][MAX_SIZE], size_t rows, size_t cols, size_t s) {
	if (!validateSize(rows) || !validateSize(cols)) {
		cout << "Invalid size!" << endl;
		return;
	}
	if (!validateSize(s)) {
		cout << "Invalid s!" << endl;
		return;
	}

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (i + j == s) {
				cout << matrix[i][j] << " ";
			}
		}
	}
	cout << endl;
}

//zad4
bool isMagicSquare(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
	if (!validateSize(rows) || !validateSize(cols) || rows != cols) {
		cout << "Invalid size!" << endl;
		return false;
	}

	int magicSum = 0;
	//find the magic sum - find the sum of the first row
	//we will compare this sum to every other sum. If any sum is different than the magic sum, the matrix is not a magic square
	for (size_t j = 0; j < cols; j++) {
		magicSum += matrix[0][j];
	}

	//compare all the rows
	for (size_t i = 1; i < rows; i++) {
		int rowSum = 0;
		for (size_t j = 0; j < cols; j++) {
			rowSum += matrix[i][j];
		}
		if (rowSum != magicSum) {
			return false;
		}
	}

	//compare all the columns
	for (size_t j = 0; j < cols; j++) {
		int colSum = 0;
		for (size_t i = 0; i < rows; i++) {
			colSum += matrix[i][j];
		}
		if (colSum != magicSum) {
			return false;
		}
	}

	//compare main diagonal
	int mainDiagonalSum = 0;
	for (size_t i = 0; i < rows; i++) {
		mainDiagonalSum += matrix[i][i];
	}
	if (mainDiagonalSum != magicSum) {
		return false;
	}

	//compare secondary diagonal
	int secondaryDiagonalSum = 0;
	for (size_t i = 0; i < rows; i++) {
		secondaryDiagonalSum += matrix[i][rows - i - 1];
	}
	if (secondaryDiagonalSum != magicSum) {
		return false;
	}

	return true;
}

//zad5
//auxiliary function - print matrix
void printMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
	if (!validateSize(rows) || !validateSize(cols)) {
		cout << "Invalid size!" << endl;
		return;
	}

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void transposeMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
	if (!validateSize(rows) || !validateSize(cols)) {
		cout << "Invalid size!" << endl;
		return;
	}

	int transposedMatrix[MAX_SIZE][MAX_SIZE] = { 0 };
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			transposedMatrix[j][i] = matrix[i][j];
		}
	}

	printMatrix(transposedMatrix, cols, rows);
}

//zad6
bool isTriangular(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
	if (!validateSize(rows) || !validateSize(cols) || rows != cols) {
		cout << "Invalid size!" << endl;
		return false;
	}

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < i; j++) {
			if (matrix[i][j] != 0) {
				return false;
			}
		}
	}

	return true;
}

void multiplyMatrices(int matrix1[][MAX_SIZE], size_t rows1, size_t cols1,
	int matrix2[][MAX_SIZE], size_t rows2, size_t cols2) {
	if (!validateSize(rows1) || !validateSize(cols1) ||
		!validateSize(rows2) || !validateSize(cols2)) {
		cout << "Invalid size!" << endl;
		return;
	}

	if (cols1 != rows2) {
		cout << "Multiplication impossible!" << endl;
		return;
	}

	int matrixProduct[MAX_SIZE][MAX_SIZE] = { 0 };
	int currentSumProduct = 0;
	for (size_t i1 = 0; i1 < rows1; i1++) {
		for (size_t j2 = 0; j2 < cols2; j2++) {
			for (size_t k = 0; k < rows2; k++) {
				currentSumProduct += matrix1[i1][k] * matrix2[k][j2];
			}
			matrixProduct[i1][j2] = currentSumProduct;
			currentSumProduct = 0;
		}
	}

	printMatrix(matrixProduct, rows1, cols2);

}


//for testing
int main() {

	int matrix1[3][MAX_SIZE] = { {1, 2, 3}, {3, 3, 3}, {1, 1, 1} };
	printSumOfElementsInEachRow(matrix1, 3, 3);
	printDiagonals(matrix1, 3);
	printElementsOfMatrixWhoseIndexesSumUpToS(matrix1, 3, 3, 2);
	cout << isMagicSquare(matrix1, 3, 3) << " ";
	int matrix2[3][MAX_SIZE] = { {2, 7, 6}, {9, 5, 1}, {4, 3, 8} };
	cout << isMagicSquare(matrix2, 3, 3) << endl;
	int matrix3[3][MAX_SIZE] = { {2, 7, 6, 1}, {9, 5, 1, 2}, {4, 3, 8, 10} };
	transposeMatrix(matrix3, 3, 4);
	int matrix4[3][MAX_SIZE] = { { 1, 2, 3 }, {0, 5, 6,}, {0, 0, 9} };
	cout << isTriangular(matrix4, 3, 3) << " " << isTriangular(matrix1, 3, 3) << endl;
	int matrix5[4][MAX_SIZE] = { {1, 2, 3}, {0, 2, 3}, {0, 0, 1}, {1, 0, 2} };
	multiplyMatrices(matrix5, 4, 3, matrix3, 3, 4);




	return 0;
}