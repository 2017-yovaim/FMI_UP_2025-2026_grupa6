#include <iostream>
using namespace std;

const int MAX_SIZE = 50;
const double EPSILON = 0.0002;

//auxiliary function - validates sizes
bool isValidSize(int size) {
	return size >= 1 && size <= MAX_SIZE;
}

//auxiliary function - return absolute value
double myAbs(double num) {
	return num > 0 ? num : (num * -1);
}

//auxiliary function - swap the values of two variables
void mySwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//auxiliary function - print a matrix
void printMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
	if (!isValidSize(rows) || !isValidSize(cols)) {
		return;
	}

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

//zad1
double findClosestToAverageElement(double arr[], size_t size) {
	if (!isValidSize(size)) {
		return -1; //invalid input
	}

	double sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += arr[i];
	}

	double average = sum / size;

	double closestToAverage = arr[0];
	for (size_t i = 1; i < size; i++) {
		if ((myAbs(arr[i] - average)) < (myAbs(closestToAverage - average))) {
			closestToAverage = arr[i];
		}
	}

	return closestToAverage;
}

//zad2
void findIndexesOfBiggestAscendingSubarray(int arr[], size_t size, int& start, int& end) {
	if (!isValidSize(size)) {
		return; //invalid input
	}

	int biggestStart = 0, biggestEnd = 0, currentStart = 0, 
		currentEnd = 0, biggestLength = 0, currentLength = 0;

	for (size_t i = 0; i < size - 1; i++) {
		if (arr[i] <= arr[i + 1]) {
			currentEnd++;
			currentLength++;
		}
		else {
			if (currentLength > biggestLength) {
				biggestLength = currentLength;
				biggestStart = currentStart;
				biggestEnd = currentEnd;
			}
			currentStart = i + 1;
			currentEnd = i + 1;
			currentLength = 1;
		}
	}

	if (currentLength > biggestLength) {
		biggestLength = currentLength;
		biggestStart = currentStart;
		biggestEnd = currentEnd;
	}

	start = biggestStart;
	end = biggestEnd;
}

//zad3
bool isSaw(int arr[], size_t size) {
	if (!isValidSize(size)) {
		return false;
	}

	//if one element - automatically true
	if (size == 1) {
		return true;
	}

	//no need to check the first and last elements - they will always be >= or <= to a single other number
	for (size_t i = 1; i < size - 1; i++) {
		if ((arr[i] > arr[i + 1] && arr[i] < arr[i - 1]) || (arr[i] < arr[i + 1] && arr[i] > arr[i - 1])) {
			return false;
		}
	}

	return true;
}

//zad4
bool isPartitionable(int arr[], size_t size) {
	if (!isValidSize(size)) {
		return false;
	}
	if (size == 1) {
		return false;
	}

	int leftSum = 0, rightSum = 0;

	for (size_t i = 0; i < size; i++) {
		leftSum += arr[i];

		for (size_t j = i + 1; j < size; j++) {
			rightSum += arr[j];
		}

		if (leftSum == rightSum) {
			return true;
		}
		rightSum = 0;
	}

	return false;
}

//zad5
void transposeSquareMatrix(int matrix[][MAX_SIZE], size_t size) {
	if (!isValidSize(size)) {
		return;
	}

	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = i + 1; j < size; j++) {
			mySwap(matrix[i][j], matrix[j][i]);
		}
	}
}

//auxiliary function - checks if number is contained in array
bool numberIsInArray(int arr[], size_t size, int num) {
	if (!isValidSize(size)) {
		return false;
	}

	for (size_t i = 0; i < size; i++) {
		if (num == arr[i]) {
			return true;
		}
	}

	return false;
}

//zad6
void printAlikeColumnIndexes(int matrix[][MAX_SIZE], size_t rows, size_t cols, size_t colIndex) {
	if (!isValidSize(rows) || !isValidSize(cols)) {
		cout << "Invalid input!" << endl;
		return;
	}

	if (colIndex >= MAX_SIZE) {
		cout << "Invalid index!" << endl;
		return;
	}

	//copy the column we're examining
	int col[MAX_SIZE];
	for (int i = 0; i < rows; i++) {
		col[i] = matrix[i][colIndex];
	}

	int currentCol[MAX_SIZE];
	for (size_t j = 0; j < cols; j++) {
		if (j == colIndex) {
			continue; //skip the column we're examining
		}

		//check that all elements of the current col belong in the target col
		bool skipColumn = false;
		for (size_t i = 0; i < rows; i++) {
			currentCol[i] = matrix[i][j];
			if (!numberIsInArray(col, rows, currentCol[i])) {
				skipColumn = true;
				break;
			}
		}

		if (skipColumn) {
			continue;
		}

		//check that all elements of the target col belong in the current col
		for (size_t i = 0; i < rows; i++) {
			if (!numberIsInArray(currentCol, rows, matrix[i][colIndex])) {
				skipColumn = true;
				break;
			}
		}

		if (!skipColumn) {
			cout << j << " ";
		}
	}

	cout << endl;
}


//for testing
int main() {
	//double arr[] = { 1, 2, 3, 4, 11 };
	//cout << findClosestToAverageElement(arr, 5) << endl;

	int arr2[] = { -15, 10, 3, 5, 6, 7, 8, 1, 2, 3 };
	int start = 0, end = 0;
	findIndexesOfBiggestAscendingSubarray(arr2, 10, start, end);
	cout << start << " " << end << endl;

	int sawArr[] = { 1, 10, 7, 8, 5, 6, 6 };
	cout << isSaw(sawArr, 7) << " " << isSaw(arr2, 10) << endl;

	int arr3[] = { 1, 2, 3, 4, 10 };
	cout << isPartitionable(arr3, 5) << " " << isPartitionable(arr3, 4) << endl; //note - size 4 will just make the function think
	//that the array is smaller than it is

	int matrix[3][MAX_SIZE] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	printMatrix(matrix, 3, 3);
	transposeSquareMatrix(matrix, 3);
	printMatrix(matrix, 3, 3);

	int matrix2[4][MAX_SIZE] = { {1, 2, 3}, {3, 2, 1}, {1, 4, 1}, {1, 2, 1} };
	printAlikeColumnIndexes(matrix2, 4, 3, 0);





	return 0;
}