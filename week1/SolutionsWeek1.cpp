//solutions to Week 1

#include <iostream>
using namespace std;


int main()
{
    //zad1
    int day;
    cout << "Please enter a number: " << endl;
    cin >> day;
    cout << (day >= 1 && day <= 31) << endl;

    //zad2
    int a, b;
    cout << "Please enter two numbers: " << endl;
    cin >> a >> b;
    cout << (a / b) << " " << (a % b) << endl;

    //zad3
    int km;
    cout << "please enter a number representing kilometres: " << endl;
    cin >> km;
    cout << km << " kilometres is " << (km * 0.621371) << " miles." << endl;

    //zad4
    int a, b, c, d;
    cout << "Please enter four numbers representing two intervals: " << endl;
    cin >> a >> b >> c >> d;
    bool cross = (b >= c) && (b <= d); //tail end of [a, b] overlaps [c, d]
    cross = cross || (a >= c && b <= d); //beginning of [a, b] overlaps [c, d]
    cout << cross << endl;



    //zad5
    int a, b, c, d;
    cout << "Please enter 4 numbers: " << endl;
    cin >> a >> b >> c >> d;
    int diff = b - a;
    cout << ((c - b == diff) && (d - c == diff)) << endl;

    //zad6
    int number;
    cout << "Please enter a number: " << endl;
    cin >> number;
    cout << (number % 2 == 0 && number % 3 != 0) << endl;

    //zad7
    int a, b, c;
    cout << "Please enter 3 numbers: " << endl;
    cin >> a >> b >> c;
    cout << (a < 0 || b < 0 || c < 0) << endl;

    //zad8
    double a, b, c, x;
    cout << "Please enter a, b, c and x for the polinom a*x^2 + b*x + c:" << endl;
    cin >> a >> b >> c >> x;
    double result = (a * (x * x)) + (b * x) + c;
    cout << result << endl;

    //zad9
    int totalSeconds;
    cout << "Please enter seconds: " << endl;
    cin >> totalSeconds;
    int days = totalSeconds / 86400;
    int remainingSeconds = totalSeconds %= 86400;
    remainingSeconds %= 86400;
    int hours = totalSeconds / 3600;
    remainingSeconds %= 3600;
    int minutes = remainingSeconds / 60;
    remainingSeconds %= 60;
    cout << days << " " << hours << " " << minutes << " " << remainingSeconds << endl;

    //zad10
    int number;
    cout << "Please enter a number: " << endl;
    cin >> number;
    int firstDigit = number / 1000;
    int secondDigit = (number % 1000) / 100;
    int thirdDigit = (number % 100) / 10;
    int fourthDigit = number % 10;

    int mirroredNumber = (fourthDigit * 1000) + (thirdDigit * 100) + (secondDigit * 10) + firstDigit;
    cout << mirroredNumber << endl;

    return 0;
}


