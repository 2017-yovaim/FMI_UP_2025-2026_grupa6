#include <iostream>
#include <cmath>
using namespace std;

int main() {
    {
        //zad1 BONUS
        const double DEFAULT_VALUE = 0;
        double x1 = DEFAULT_VALUE, y1 = DEFAULT_VALUE, x2 = DEFAULT_VALUE, y2 = DEFAULT_VALUE;

        cout << "Enter coordinates of two points: ";
        cin >> x1 >> y1 >> x2 >> y2;

        double distance = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
        cout << "The distance between the two points is: " << distance << endl;
    }

    {
        //zad2 BONUS
        const double DEFAULT_VALUE = 0;
        double vSlower = DEFAULT_VALUE, vFaster = DEFAULT_VALUE, distanceBtwThem = DEFAULT_VALUE;

        cout << "Enter the speed of the two runners and the distance between them: ";
        cin >> vSlower >> vFaster >> distanceBtwThem;

        if (vSlower >= vFaster) {
            cout << "The two will never meet." << endl;
            return -1; //end the program
        }

        double time = distanceBtwThem / (vFaster - vSlower);
        cout << "The faster runner will catch up with the slower one after " << time << " hours.";
    }

    {
        //zad3 BONUS
        const int DEFAULT_VALUE = 0;
        int numOne = DEFAULT_VALUE, numTwo = DEFAULT_VALUE;

        cout << "Enter two numbers: ";
        cin >> numOne >> numTwo;

        int maxNum = (numOne + numTwo + abs(numOne - numTwo)) / 2;
        cout << "The bigger number between the two is " << maxNum << endl;
    }

    {
        //zad4 BONUS
        const int DEFAULT_VALUE = 0;
        int x1 = DEFAULT_VALUE, y1 = DEFAULT_VALUE, x2 = DEFAULT_VALUE, y2 = DEFAULT_VALUE;

        cout << "Enter coordinates of two diagonal corners of a rectangle: ";
        cin >> x1 >> y1 >> x2 >> y2;

        int width = abs(x2 - x1);
        int height = abs(y2 - y1);
        int area = width * height;

        cout << "The area of the rectangle is: " << area << endl;
    }

    return 0;
}