//solutions to problems from week 3
	//I hope that you see how many times I had to write down the algorithm for iterating the digits of a number
	//I hope that it convinces you of the usefulness of functions - so much of this code would not have to repeat
#include <iostream>
using namespace std;

int main() {

	//zad1
	cout << "Please enter a number: ";
	int num;
	cin >> num;
	int factoriel = 1;
	for (int i = 2; i <= num; i++) {
		factoriel *= i;
	}
	cout << num << "! = " << factoriel << endl;

	//zad2
	int counter = 0;
	int sum = 0;
	int input = 0;
	while (counter < 3) {
		cout << "Please enter a number: ";
		cin >> input;
		if (input % 7 == 0) {
			sum += input;
			counter++;
		}
	}
	cout << "The sum is " << sum << endl;

	//zad3
	cout << "Please enter a number: ";
	int number;
	cin >> number;
	int mirroredNumber = 0;
	int numberCopy = number; //we will be iterating on numberCopy so we don't lose the original number
	while (numberCopy != 0) {
		int lastDigit = numberCopy % 10;
		(mirroredNumber *= 10) += lastDigit;
		numberCopy /= 10;
	}
	cout << "The mirror of " << number << " is " << mirroredNumber << endl;

	//zad4
	cout << "Please enter two numbers: " << endl;
	int a = 0, b = 0;
	cin >> a >> b;
	int min = a;
	if (min > b) {
		min = b;
	}

	cout << "The common dividers of " << a << " and " << b << " are: ";
	for (int i = min; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			cout << i << " ";
		}
	}
	cout << endl;

	//zad5
	int n = 0;
	cout << "Please enter n: ";
	cin >> n;
	int min = 0, max = 0;
	int input = 0;
	for (int i = 0; i < n; i++) {
		cout << "Enter a number: ";
		cin >> input;
		if (i == 0) {
			//this assures that the algorithm doesn't break if the smallest number is larger than 0 or the largest number is smaller than 0
			//try to figure out how it would go wrong if this if wasn't here
			max = min = input;
			continue;
		}
		if (min > input) {
			min = input;
		}
		if (max < input) {
			max = input;
		}
	}
	cout << "The smallest number is " << min << " and the largest is " << max << endl;

	//zad6
	cout << "Please enter a number: ";
	int n = 0; 
	cin >> n;
	if (n == 1 || n == 2) {
		cout << n << endl;
		return 0;
	}
	int a = 1, b = 1; //first and second Fibbonaci numbers
	for (int i = 3; i <= n; i++) {
		int temp = a;
		a = b;
		b = b + temp;
	}
	cout << "Fibbonaci number " << n << " is " << b << endl;

	//zad7
	cout << "Please enter a number: ";
	int num = 0;
	cin >> num;
	bool isPrime = true;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			isPrime = false;
			break;
		}
	}

	if (isPrime) {
		cout << "Prime" << endl;
	} 
	else {
		cout << "Not prime" << endl;
	}

	//zad8
	cout << "Please enter a number: ";
	int num = 0;
	cin >> num;
	int digitCounter = 0;
	if (num == 0) {
		cout << "The number 0 has 1 digit" << endl;
		return 0;
	}
	int numCopy = num;
	while (numCopy != 0) {
		digitCounter++;
		numCopy /= 10;
	}
	cout << "The number " << num << " has " << digitCounter << " digits" << endl;

	//zad9
	int m = 0, n = 0;
	cout << "Please enter m and n: " << endl;
	cin >> m >> n;
	char symbol = '-';
	for (int i = 1; i <= m; i++) {
		cout << "|";
		if (i % 2 == 0) {
			symbol = '*';
		}
		else {
			symbol = '-';
		}
		for (int j = 0; j < n; j++) {
			cout << symbol;
		}
		cout << "|" << endl;
	}

	//zad10
	int n = 0;
	cout << "Please enter n: ";
	cin >> n;
	int totalSpacesNeededOnOneSide = n - 1;
	for (int i = 0; i < n; i++) {
		int currentSpacesNeededOnOneSide = totalSpacesNeededOnOneSide - i;
		for (int j = 0; j < currentSpacesNeededOnOneSide; j++) {
			cout << " ";
		}
		int maxNumberInRow = n - currentSpacesNeededOnOneSide;
		for (int j = 1; j <= maxNumberInRow; j++) {
			cout << j;
		}
		for (int j = maxNumberInRow - 1; j > 0; j--)
		{
			cout << j;
		}
		cout << endl;
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < totalSpacesNeededOnOneSide; j++) {
			cout << " ";
		}
		cout << "*" << endl;
	}


	//zad11
	cout << "Please enter n: ";
	int n = 0;
	cin >> n;
	char symbol = '$';
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cout << symbol << " ";
		}
		cout << endl;
	}

	//zad12
	int num = 0, digit = 0;
	cout << "Enter a number and a digit: " << endl;
	cin >> num >> digit;
	int numCopy = num;
	int digitCounter = 0;
	while (numCopy != 0) {
		int lastDigit = numCopy % 10;
		if (lastDigit == digit) {
			digitCounter++;
		}
		numCopy /= 10;
	}
	cout << "The digit " << digit << " is met in number " << num << " " << digitCounter << " times" << endl;

	//zad13
	int number = 0;
	cout << "Please enter a number: " << endl;
	cin >> number;
	if (number == 0) {
		cout << number << endl;
		return 0;
	}
	int numberCopy = number;
	if (number < 0) {
		cout << "- ";
		numberCopy *= -1;
	}

	int mirroredNumber = 0;
	while (numberCopy != 0) {
		int lastDigit = numberCopy % 10;
		(mirroredNumber *= 10) += lastDigit;
		numberCopy /= 10;
	}

	while (mirroredNumber != 0) {
		cout << mirroredNumber % 10 << " ";
		mirroredNumber /= 10;
	}

	//zad14
	int number = 0;
	cout << "Please enter a number: ";
	cin >> number;
	if (number < 10) {
		cout << "true" << endl;
		return 0;
	}
	if (number % 10 == 0) {
		cout << "false" << endl;
		return 0;
	}

	int numberCopy = number;
	int mirroredNumber = 0;
	while (numberCopy != 0) {
		int lastDigit = numberCopy % 10;
		(mirroredNumber *= 10) += lastDigit;
		numberCopy /= 10;
	}

	if (number == mirroredNumber) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	//zad15
	long long bigNumber = 0;
	cout << "Please enter a number: ";
	cin >> bigNumber;
	int currentMaxDigit = 0, currentMaxCounter = 0, maxDigit = 0, maxCounter = 0;
	long long bigNumberCopy = bigNumber;

	//get the last digit of the number for the first comparison in the loop
	int previousLastDigit = bigNumberCopy % 10;
	currentMaxDigit = previousLastDigit;
	currentMaxCounter++;
	bigNumberCopy /= 10;

	while (bigNumberCopy != 0) {
		int currentLastDigit = bigNumberCopy % 10;
		if (currentLastDigit == previousLastDigit) {
			currentMaxDigit = currentLastDigit;
			currentMaxCounter++;
		}
		else {
			currentMaxCounter = 1;
			currentMaxDigit = currentLastDigit;
			
		}
		if (currentMaxCounter >= maxCounter) {
			maxDigit = currentMaxDigit;
			maxCounter = currentMaxCounter;
		}
		previousLastDigit = currentLastDigit;
		bigNumberCopy /= 10;
	}

	cout << maxDigit << " " << maxCounter << " times" << endl;






	return 0;
}