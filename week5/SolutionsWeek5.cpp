#include <iostream>
using namespace std;

const size_t MAX_SIZE = 50;
const size_t SIZE_OF_COUNT_ARRAY = 10;

//auxiliary function - print an array
void printArray(int arr[], size_t size) {
	if (size <= 0)
		return;

	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//auxiliary function - check validity of size
bool sizeIsValid(int size) {
	return size >= 0 && size <= MAX_SIZE;
}


//zad1
double findAverageOfElementsOfArray(int arr[], size_t size) {
	if (!sizeIsValid(size)) {
		cout << "Invalid size!" << endl;
		return false;
	}

	double sumOfElements = 0;
	for (size_t i = 0; i < size; i++) {
		sumOfElements += arr[i];
	}

	return sumOfElements / size;
}

//zad2
/* note - this can be done by copying the array, reversing it, and going comparing the elements of the two arrays
* but that wastes memory so we're doing it in-place
*/
bool arrayIsPalindrome(int arr[], int size) {
	if (!sizeIsValid(size)) {
		cout << "Invalid size!" << endl;
		return false;
	}
	for (int i = 0, j = size - 1; i < size && i <= j; i++, j--) {
		if (arr[i] != arr[j])
			return false;
	}
	return true;
}

//zad3
int sumOfElementsInIndexesDivisibleByThree(int arr[], size_t size) {
	if (!sizeIsValid(size)) {
		cout << "Invalid size!" << endl;
		return -1;
	}
	int sum = arr[0];
	for (size_t i = 3; i < size; i += 3) {
		sum += arr[i];
	}

	return sum;
}

//zad4
//auxiliary function - find if a digit is present in a number
bool hasDigit(int number, int digit) {
	if (digit < 0 || digit > 9) //not a digit
		return false;

	while (number != 0) {
		int lastDigit = number % 10;
		if (lastDigit == digit) {
			return true;
		}

		number /= 10;
	}
	return false;
}

void nullElementsWithoutIndexPresentAsDigit(int arr[], size_t size) {
	if (size > 10) {
		cout << "Invalid input - size must be at most 10" << endl;
		return;
	}

	for (size_t i = 0; i < size; i++) {
		if (!hasDigit(arr[i], i)) {
			arr[i] = 0;
		}
	}
}

//zad5
bool arraysAreComposedOfSameSets(int arr1[], size_t size1, int arr2[], size_t size2) {
	if (!sizeIsValid(size1) || !sizeIsValid(size2)) {
		cout << "Invalid size!" << endl;
		return false;
	}

	bool numberIsPresentInOtherArray = false;
	for (size_t i = 0; i < size1; i++) {
		numberIsPresentInOtherArray = false;
		for (size_t j = 0; j < size2; j++) {
			if (arr1[i] == arr2[j]) {
				numberIsPresentInOtherArray = true;
			}
		}
		if (numberIsPresentInOtherArray == false) {
			return false;
		}
	}

	for (size_t j = 0; j < size2; j++) {
		numberIsPresentInOtherArray = false;
		for (size_t i = 0; i < size1; i++) {
			if (arr1[i] == arr2[j]) {
				numberIsPresentInOtherArray = true;
			}
		}
		if (numberIsPresentInOtherArray == false) {
			return false;
		}
	}

	return true;
}

//zad6
int countFixedElementsInArray(int arr[], int size) {
	if (!sizeIsValid(size)) {
		cout << "Invalid size!" << endl;
		return -1;
	}

	int counterOfFixedElements = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == i) {
			counterOfFixedElements++;
		}
	}

	return counterOfFixedElements;
}

//zad7
/* algorithm - two vectors are linearly dependent if an only if there exists a scalar such that
* one of the vectors is the scalar multiple of the other
*/
bool areLinearlyDependent(int arr1[], size_t size1, int arr2[], size_t size2) {
	if (!sizeIsValid(size1) || !sizeIsValid(size2)) {
		cout << "Invalid size!" << endl;
		return false;
	}

	if (size1 != size2) {
		return false; //linear dependence undefined in different vector spaces
	}

	double scalar = (double)arr1[0] / arr2[0];

	for (size_t i = 1; i < size1; i++) {
		if ((double)arr1[i] / arr2[i] != scalar)
			return false;
	}

	return true;

}

//zad8
/* algorithm - count how many times each of the numbers 0 through 9 are contained in each of the arrays
* and then compare whether the counts are equal for each array
*/
bool secondArrayIsPermutationOfFirst(int arr1[], size_t size1, int arr2[], size_t size2) {
	if (!sizeIsValid(size1) || !sizeIsValid(size2)) {
		cout << "Invalid size!" << endl;
		return false;
	}

	if (size1 != size2) {
		cout << "Sizes need to be equal!" << endl;
		return false;
	}

	int count1[SIZE_OF_COUNT_ARRAY] = { 0 }; //each index corresponds to its number, and the value - to the number of times the number is present in the array
	int count2[SIZE_OF_COUNT_ARRAY] = { 0 };

	for (size_t i = 0; i < size1; i++) {
		if (arr1[i] < 0 || arr1[i] > 9) {
			cout << "Invalid data!" << endl;
			return false;
		}

		count1[arr1[i]]++;
	}

	for (size_t j = 0; j < size2; j++) {
		if (arr2[j] < 0 || arr2[j] > 9) {
			cout << "Invalid data!" << endl;
			return false;
		}
		
		count2[arr2[j]]++;
	}

	for (size_t i = 0; i < SIZE_OF_COUNT_ARRAY; i++) {
		if (count1[i] != count2[i]) {
			return false;
		}
	}

	return true;
}


//for testing
int main() {
	int arr1[] = { 1, 2, 3, 4 };
	cout << findAverageOfElementsOfArray(arr1, 4) << endl;
	int arr2[] = { 1, 2, 2, 1 };
	cout << arrayIsPalindrome(arr1, 4) << " " << arrayIsPalindrome(arr2, 4) << endl;
	cout << sumOfElementsInIndexesDivisibleByThree(arr1, 4) << " " << sumOfElementsInIndexesDivisibleByThree(arr2, 4) << endl;
	int arr3[] = {10, 12, 33, 42, 45, 56, 1, 7, 90, 39};
	nullElementsWithoutIndexPresentAsDigit(arr3, 10);
	printArray(arr3, 10);
	int arr4[] = { 1, 1, 2, 2, 1, 1, 1 };
	cout << arraysAreComposedOfSameSets(arr1, 4, arr2, 4) << " " << arraysAreComposedOfSameSets(arr2, 4, arr4, 7) << endl;
	cout << countFixedElementsInArray(arr4, 7) << endl;
	int arr5[] = { 1, 2, 3, 4, 5, 6, 7 };
	int arr6[] = { 1, 1, 1, 1, 1, 2, 2 };
	cout << secondArrayIsPermutationOfFirst(arr4, 7, arr5, 7) << " " << secondArrayIsPermutationOfFirst(arr4, 7, arr6, 7) << endl;
	


	return 0;
}