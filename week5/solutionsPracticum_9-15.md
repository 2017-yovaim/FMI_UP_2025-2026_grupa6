### Задача 9:

```cpp
#include <iostream>
using namespace std;

const size_t MIN_ARR_SIZE = 1, MAX_ARR_SIZE = 50;

bool isSizeValid(size_t size) {
    return (size >= MIN_ARR_SIZE && size <= MAX_ARR_SIZE);
}

 int main() {
    size_t size = 0;
    cout << "Enter array size: ";
    cin >> size;

    if (!isSizeValid(size)) {
        cout << "Invalid size!";
        return 1;
    }

    int arr[MAX_ARR_SIZE]{0};
    cout << "Enter array elements: ";
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int minNum = arr[0], maxNum = arr[0];
    for (size_t i = 0; i < size; i++) {
        if (arr[i] < minNum)
            minNum = arr[i];
        if (arr[i] > maxNum)
            maxNum = arr[i];
    }

    cout << "Max: " << maxNum << endl;
    cout << "Min: " << minNum << endl;
}
```

### Задача 10:

```cpp
#include <iostream>
using namespace std;

const size_t MIN_ARR_SIZE = 1, MAX_ARR_SIZE = 50;

bool isSizeValid(size_t size) {
    return (size >= MIN_ARR_SIZE && size <= MAX_ARR_SIZE);
}

void mySwap(int& numOne, int& numTwo) {
    int temp = numOne;
    numOne = numTwo;
    numTwo = temp;
}

void reverseArr(int arr[], size_t size) {
    for (size_t i = 0, j = size - 1; i < j; i++, j--) {
        mySwap(arr[i], arr[j]);
    }
}

void printArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

 int main() {
    size_t size = 0;
    cout << "Enter array size: ";
    cin >> size;

    if (!isSizeValid(size)) {
        cout << "Invalid size!";
        return 1;
    }

    int arr[MAX_ARR_SIZE]{0};
    cout << "Enter array elements: ";
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }

    reverseArr(arr, size);
    printArr(arr,size);
}
```

### Задача 11:

```cpp
#include <iostream>
using namespace std;

const size_t MIN_ARR_SIZE = 1, MAX_ARR_SIZE = 50;

bool isSizeValid(size_t size) {
    return (size >= MIN_ARR_SIZE && size <= MAX_ARR_SIZE);
}

int countXInArr(int arr[], size_t size, int x) {
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == x)
            count++;
    }

    return count;
}

int main() {
    size_t size = 0;
    cout << "Enter array size: ";
    cin >> size;

    if (!isSizeValid(size)) {
        cout << "Invalid size!";
        return 1;
    }

    int arr[MAX_ARR_SIZE]{0};
    cout << "Enter array elements: ";
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int x = 0;
    cout << "Enter a number: ";
    cin >> x;

    cout << "Count of " << x << " in array is " << countXInArr(arr, size, x);
}
```

### Задача 12:

```cpp
#include <iostream>
using namespace std;

const size_t MIN_ARR_SIZE = 1, MAX_ARR_SIZE = 50;

bool isSizeValid(size_t size) {
     return (size >= MIN_ARR_SIZE && size <= MAX_ARR_SIZE);
}

void mySwap(int& numOne, int& numTwo) {
     int temp = numOne;
     numOne = numTwo;
     numTwo = temp;
}

void bubbleSort(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        bool isSwapped = false;
        size_t loopStop = size - i - 1;
        for (size_t j = 0; j < loopStop; j++) {
            if (arr[j] > arr[j + 1]) {
                mySwap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }

        if (isSwapped == false)
            break;
    }
}

void printArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    size_t size = 0;
    cout << "Enter array size: ";
    cin >> size;

    if (!isSizeValid(size)) {
        cout << "Invalid size!";
        return 1;
    }

    int arr[MAX_ARR_SIZE]{0};
    cout << "Enter array elements: ";
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, size);
    printArr(arr, size);
}
```

### Задача 13:

```cpp
#include <iostream>
using namespace std;

const size_t MIN_ARR_SIZE = 1, MAX_ARR_SIZE = 50;

bool isSizeValid(size_t size) {
    return (size >= MIN_ARR_SIZE && size <= MAX_ARR_SIZE);
}

void printUnique(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        bool isUnique = true;
        for (size_t j = 0; j < size; j++) {
            if ((arr[i] == arr[j]) && (i != j)) {
                isUnique = false;
                break;
            }
        }

        if (isUnique)
            cout << arr[i] << " ";
    }
}

int main() {
    size_t size = 0;
    cout << "Enter array size: ";
    cin >> size;

    if (!isSizeValid(size)) {
        cout << "Invalid size!";
        return 1;
    }

    int arr[MAX_ARR_SIZE]{0};
    cout << "Enter array elements: ";
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }

    printUnique(arr, size);
}
```

### Задача 14:

```cpp
#include <iostream>
using namespace std;

const size_t MIN_ARR_SIZE = 1, MAX_ARR_SIZE = 50;
const size_t BUFF_MAX_SIZE = 2 * MAX_ARR_SIZE;

bool isSizeValid(size_t size) {
    return (size >= MIN_ARR_SIZE && size <= MAX_ARR_SIZE);
}

void mergeTwoSortedArrs(int arrOne[], size_t sizeOne, int arrTwo[], size_t sizeTwo, int buffer[]) {
    int counterOne = 0, counterTwo = 0, bufferCounter = 0;

    while (counterOne < sizeOne && counterTwo < sizeTwo) {
        if (arrOne[counterOne] <= arrTwo[counterTwo]) {
            buffer[bufferCounter] = arrOne[counterOne];
            counterOne++;
        }
        else {
            buffer[bufferCounter] = arrTwo[counterTwo];
            counterTwo++;
        }

        bufferCounter++;
    }

    while (counterOne < sizeOne) {
        buffer[bufferCounter] = arrOne[counterOne];
        counterOne++;
        bufferCounter++;
    }

    while (counterTwo < sizeTwo) {
        buffer[bufferCounter] = arrTwo[counterTwo];
        counterTwo++;
        bufferCounter++;
    }
}

void printArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    size_t sizeOne = 0;
    cout << "Enter first array size: ";
    cin >> sizeOne;

    if (!isSizeValid(sizeOne)) {
        cout << "Invalid size!";
        return 1;
    }

    int arrOne[MAX_ARR_SIZE]{0};
    cout << "Enter first array elements: ";
    for (size_t i = 0; i < sizeOne; i++) {
        cin >> arrOne[i];
    }

    size_t sizeTwo = 0;
    cout << "Enter second array size: ";
    cin >> sizeTwo;

    if (!isSizeValid(sizeTwo)) {
        cout << "Invalid size!";
        return 2;
    }

    int arrTwo[MAX_ARR_SIZE]{0};
    cout << "Enter second array elements: ";
    for (size_t i = 0; i < sizeTwo; i++) {
        cin >> arrTwo[i];
    }

    int buffer[BUFF_MAX_SIZE]{0};
    int buffSize = sizeOne + sizeTwo;
    mergeTwoSortedArrs(arrOne, sizeOne, arrTwo, sizeTwo, buffer);
    printArr(buffer, buffSize);
}
```

### Задача 15:

```cpp
#include <iostream>
using namespace std;

const size_t MIN_ARR_SIZE = 1, MAX_ARR_SIZE = 50;

bool isSizeValid(size_t size) {
    return (size >= MIN_ARR_SIZE && size <= MAX_ARR_SIZE);
}

int maxLengthSameEls(int arr[], size_t size) {
    int maxLength = 1;
    int currLength = 1;

    for (size_t i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1])
            currLength++;
        else {
            if (currLength > maxLength)
                maxLength = currLength;

            currLength = 1;
        }
    }

    if (currLength > maxLength)
        maxLength = currLength;

    return maxLength;
}

int main() {
    size_t size = 0;
    cout << "Enter array size: ";
    cin >> size;

    if (!isSizeValid(size)) {
        cout << "Invalid size!";
        return 1;
    }

    int arr[MAX_ARR_SIZE]{0};
    cout << "Enter first array elements: ";
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Length of longest route of consecutive elements: " << maxLengthSameEls(arr, size) << endl;
}
```