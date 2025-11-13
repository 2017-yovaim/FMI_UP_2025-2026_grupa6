#include <iostream>
using namespace std;

//zad1
int myAbs(int num) {
	return (num >= 0) ? num : (num * -1);
}

int myMin(int x, int y) {
	return (x <= y) ? x : y;
}

int myMax(int x, int y) {
	return (x >= y) ? x : y;
}

double myPow(double base, int exp) {
	if (exp == 0)
		return 1;

	double result = base;
	int absExp = myAbs(exp);
	for (int i = 1; i < absExp; i++) {
		result *= base;
	}

	if (exp < 0) {
		result = 1.0 / result;
	}

	return result;

}

//zad2
int countDigits(int number) {
	if (number > -10 && number < 10)
		return 1;

	int count = 0;
	while (number != 0) {
		count++;
		number /= 10;
	}

	return count;
}

//zad3
void printGeometricProgression(int a0, int q, int n) {
	if (n == 0)
		return; //nothing to print - no numbers

	int currentNumber = a0;
	for (int i = 0; i < n; i++) {
		cout << currentNumber << " ";
		currentNumber *= q;
	}
	cout << endl;
}

//zad4
//auxiliary function - reverses a number
int reverseNumber(int number) {
	if (number > -10 && number < 10)
		return number; //one digit - nothing to reverse

	int reversedNumber = 0;

	while (number != 0) {
		int lastDigit = number % 10;
		(reversedNumber *= 10) += lastDigit;
		number /= 10;
	}

	return reversedNumber;
}

bool isPalindrom(int number) {
	if (number % 10 == 0)
		return false; //optimization

	return number == reverseNumber(number);
}

//zad5
int concatenateNumbers(int num1, int num2) {
	int result = num1;
	int reversedNum2 = reverseNumber(num2);

	while (reversedNum2 != 0) {
		int digitToCancatenate = reversedNum2 % 10;
		(result *= 10) += digitToCancatenate;
		reversedNum2 /= 10;
	}
	return result;
}

//zad6
int sumOfDigitsOfNumber(int number) {
	if (myAbs(number) < 10) {
		return myAbs(number);
	}

	if (number < 0) {
		number *= -1;
	}

	int sum = 0;
	while (number != 0) {
		int lastDigit = number % 10;
		sum += lastDigit;
		number /= 10;
	}

	return sum;
}

int zad6(int number) {
	int sum = 0;

	do {
		sum = sumOfDigitsOfNumber(number);
		number = sum;
	} while (sum >= 10);

	return sum;
}

//zad7
bool isDivisibleWithoutModule(int number, int divisor) {
	int result = number / divisor;
	result *= divisor;
	return result == number;

	/* explanation:
		if number is divisible by divisor, then dividing the number and then multiplying it by divisor
		would result in the original number.
		if it is not divisible, then the number will be smaller
	*/
}

//zad8
//auxiliary function - checks for leap years
bool isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	
}

bool isValidDate(unsigned int day, unsigned int month, unsigned int year) {
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	switch (month) {
		case 2:
			if (isLeapYear(year)) {
				return day <= 29;
			}
			else {
				return day <= 28;
			}
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: return day <= 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11: return day <= 30;
			break;
		default: cout << "This should never happen due to the checks we've done" << endl;
			return false;
	}
}

//zad9
//auxiliary function - checks if a number is perfect
bool isPerfect(unsigned int number) {
	unsigned int sumOfDivisors = 0;
	for (int i = 1; i < number; i++) {
		if (number % i == 0) {
			sumOfDivisors += i;
		}
	}
	return number == sumOfDivisors;
}

void printPerfectNumbersInRange(unsigned int start, unsigned int end) {
	if (start > end) {
		return; //incorrect input
	}

	for (int i = start; i <= end; i++) {
		if (isPerfect(i)) {
			cout << i << " ";
		}
	}
	cout << endl;
}
