//Solutions Week 2

#include <iostream>
using namespace std;

int main() {

	//zad1
	cout << "Please enter 3 numbers: " << endl;
	int a, b, c;
	cin >> a >> b >> c;
	int max = a;
	if (max < b)
	{
		max = b;
	}

	if (max < c)
	{
		max = c;
	}
	cout << "The biggest numbers is " << max << endl;

	//zad2
	cout << "Please enter a symbol: " << endl;
	char symbol;
	cin >> symbol;
	bool isLowercaseLetter = (symbol >= 'a' && symbol <= 'z' ? true : false);
	cout << isLowercaseLetter << endl;

	//zad3
	cout << "Please enter a symbol: " << endl;
	char symbol;
	cin >> symbol;
	int diff = 'a' - 'A';
	if (symbol >= 'a' && symbol <= 'z') {
		char newSymbol = symbol - diff;
		cout << newSymbol << endl;
	}
	else if (symbol >= 'A' && symbol <= 'Z') {
		char newSymbol = symbol + diff;
		cout << newSymbol << endl;
	}
	else {
		cout << "Not a letter" << endl;
	}

	//zad4
	int x1, y1, x2, y2;
	cout << "Please enter the coordinates of 2 dots: " << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	int x, y;
	cout << "Please enter the coordinates of 1 dot: " << endl;
	cin >> x >> y;
	if (x < x1 || x > x2 || y > y1 || y < y2) {
		cout << "Outside" << endl;
	}
	else if (x > x1 && x < x2 && y < y1 && y > y2) {
		cout << "Inside" << endl;
	}
	else {
		cout << "On the border" << endl;
	}

	//zad5
	int radius, x, y;
	cout << "Enter a radius and then the coordinates of 1 dot: " << endl;
	cin >> radius >> x >> y;
	int distanceFromCentreOfCircle = sqrt((x * x) + (y * y)); //Pythagorean Theorem
	if (distanceFromCentreOfCircle > radius) {
		cout << "Outside" << endl;
	}
	else if (distanceFromCentreOfCircle < radius) {
		cout << "Inside" << endl;
	}
	else {
		cout << "On the border" << endl;
	}

	//zad6
	int year;
	cout << "Please enter a year: ";
	cin >> year;
	if (year % 400 == 0) {
		cout << "Leap" << endl;
	}
	else if (year % 4 == 0) {
			if (year % 100 == 0) {
				cout << "Not leap" << endl;
			}
			else {
				cout << "Leap" << endl;
			}
	}
	else {
		cout << "Not leap" << endl;
	}

	//zad7
	int degrees;
	cout << "Please enter degrees: ";
	cin >> degrees;
	if (degrees >= 35) {
		cout << "Very hot" << endl;
	} 
	else if (degrees >= 25) {
		cout << "Hot" << endl;
	}
	else if (degrees >= 15) {
		cout << "Warm" << endl;
	}
	else if (degrees >= 5) {
		cout << "Cold" << endl;
	}
	else if (degrees < 5) {
		cout << "Freezing" << endl;
	}

	//zad8
	int date;
	cout << "Please enter a number representing a date: ";
	cin >> date;
	int day = date % 7;

	switch (day) {
		case 0: cout << "Monday";
			break;
		case 1: cout << "Tuesday";
			break;
		case 2: cout << "Wednesday";
			break;
		case 3: cout << "Thursday";
			break;
		case 4: cout << "Friday";
			break;
		case 5: cout << "Saturday";
			break;
		case 6: cout << "Sunday";
			break;
		default: cout << "Fatal error. According to the laws of Mathematics, this shouldn't be possible" << endl;
			break;
	}

	//zad9
	double num1, num2;
	char operatorSymbol;
	cout << "Please enter the simple calculation you'd like to solve: " << endl;
	cin >> num1 >> operatorSymbol >> num2;
	switch (operatorSymbol) {
		case '+': cout << (num1 + num2) << endl;
			break;
		case '-': cout << (num1 - num2) << endl;
			break;
		case '*': cout << (num1 * num2) << endl;
			break;
		case '/':
			if (num2 == 0){
				cout << "Cannot divide by 0!" << endl;
				break;
			} 
			else {
				cout << (num1 / num2) << endl;
			}
			break;
		default:
			cout << "Invalid operator. Please enter +, -, * or /" << endl;
			break;
	}

	//zad10
	int num;
	cout << "Please enter a number: ";
	cin >> num;
	if (num % 2 == 0) {
		cout << "even" << endl;
	} 
	else {
		cout << "odd" << endl;
	}

	//zad11
	//we assume that we always receive a letter
	char letter;
	cout << "Please enter a letter: ";
	cin >> letter;
	switch (letter) {
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U': cout << "vowel" << endl;
			break;
		default: cout << "consonant" << endl;
			break;
	}

	return 0;
}