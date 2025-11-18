### Задача 8:

```cpp
#include <iostream>
using namespace std;

const size_t MIN_MTRX_SIZE = 1, MAX_MTRX_SIZE = 50;

bool isSquareMtrx(size_t rows, size_t cols) {
    return (rows == cols);
}

bool areRowsAndColsValid(size_t rows, size_t cols) {
    return (rows >= MIN_MTRX_SIZE && rows <= MAX_MTRX_SIZE) && (cols >= MIN_MTRX_SIZE && cols <= MAX_MTRX_SIZE);
}

bool isSymmetrical(int mtrx[][MAX_MTRX_SIZE], size_t rows) {
    for (size_t i = 1; i < rows; i++) {
        for (size_t j = 0; j < i; j++) {
            if (mtrx[i][j] != mtrx[j][i])
                return false;
        }
    }
    return true;
}

int main() {
    size_t rows = 0, cols = 0 ;
    cout << "Enter rows and columns count: ";
    cin >> rows >> cols;

    if (!areRowsAndColsValid(rows, cols)) {
        cout << "Invalid rows and columns count!";
        return 1;
    }

    if (!isSquareMtrx(rows, cols)) {
        cout << "Matrix is not square!";
        return 2;
    }

    int mtrx[MAX_MTRX_SIZE][MAX_MTRX_SIZE]{0};
    cout << "Enter matrix elements: ";
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cin >> mtrx[i][j];
        }
    }

    if (isSymmetrical(mtrx, rows))
        cout << "symmetrical" << endl;
    else
        cout << "asymmetrical" << endl;
}
```

### Задача 9:

```cpp
#include <iostream>
using namespace std;

const size_t MIN_MTRX_SIZE = 1, MAX_MTRX_SIZE = 50;

bool areRowsAndColsValid(size_t rows, size_t cols) {
    return (rows >= MIN_MTRX_SIZE && rows <= MAX_MTRX_SIZE) && (cols >= MIN_MTRX_SIZE && cols <= MAX_MTRX_SIZE);
}

void mySwap(int& numOne, int& numTwo) {
    int temp = numOne;
    numOne = numTwo;
    numTwo = temp;
}

void mirrorLeftRight(int mtrx[][MAX_MTRX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0, k = cols - 1; j < k; j++, k--) {
            mySwap(mtrx[i][j], mtrx[i][k]);
        }
    }
}

void printMtrx(int mtrx[][MAX_MTRX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << mtrx[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    size_t rows = 0, cols = 0 ;
    cout << "Enter rows and columns count: ";
    cin >> rows >> cols;

    if (!areRowsAndColsValid(rows, cols)) {
        cout << "Invalid rows and columns count!";
        return 1;
    }

    int mtrx[MAX_MTRX_SIZE][MAX_MTRX_SIZE]{0};
    cout << "Enter matrix elements: ";
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cin >> mtrx[i][j];
        }
    }

    mirrorLeftRight(mtrx, rows, cols);
    printMtrx(mtrx, rows, cols);
}
```

### Задача 10:

```cpp
#include <iostream>
using namespace std;

const size_t MIN_MTRX_SIZE = 1, MAX_MTRX_SIZE = 50;

bool areRowsAndColsValid(size_t rows, size_t cols) {
    return (rows >= MIN_MTRX_SIZE && rows <= MAX_MTRX_SIZE) && (cols >= MIN_MTRX_SIZE && cols <= MAX_MTRX_SIZE);
}

void mySwap(int& numOne, int& numTwo) {
    int temp = numOne;
    numOne = numTwo;
    numTwo = temp;
}

void mirrorTopBottom(int mtrx[][MAX_MTRX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < cols; i++) {
        for (size_t j = 0, k = rows - 1; j < k; j++, k--) {
            mySwap(mtrx[j][i], mtrx[k][i]);
        }
    }
}

void printMtrx(int mtrx[][MAX_MTRX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << mtrx[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    size_t rows = 0, cols = 0 ;
    cout << "Enter rows and columns count: ";
    cin >> rows >> cols;

    if (!areRowsAndColsValid(rows, cols)) {
        cout << "Invalid rows and columns count!";
        return 1;
    }

    int mtrx[MAX_MTRX_SIZE][MAX_MTRX_SIZE]{0};
    cout << "Enter matrix elements: ";
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cin >> mtrx[i][j];
        }
    }

    mirrorTopBottom(mtrx, rows, cols);
    printMtrx(mtrx, rows, cols);
}
```

### Задача 11:

```cpp
#include <iostream>
using namespace std;

const size_t MIN_MTRX_SIZE = 1, MAX_MTRX_SIZE = 50;

bool areRowsAndColsValid(size_t rows, size_t cols) {
    return (rows >= MIN_MTRX_SIZE && rows <= MAX_MTRX_SIZE) && (cols >= MIN_MTRX_SIZE && cols <= MAX_MTRX_SIZE);
}

bool isSquareMtrx(size_t rows, size_t cols) {
    return (rows == cols);
}

void mySwap(int& numOne, int& numTwo) {
    int temp = numOne;
    numOne = numTwo;
    numTwo = temp;
}

void mirrorLeftRight(int mtrx[][MAX_MTRX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0, k = cols - 1; j < k; j++, k--) {
            mySwap(mtrx[i][j], mtrx[i][k]);
        }
    }
}

void mtrxTranspose(int mtrx[][MAX_MTRX_SIZE], int rows) {
    for (size_t i = 1; i < rows; i++) {
        for (size_t j = 0; j < i; j++) {
            mySwap(mtrx[i][j] ,mtrx[j][i]);
        }
    }
}

void printMtrx(int mtrx[][MAX_MTRX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << mtrx[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    size_t rows = 0, cols = 0 ;
    cout << "Enter rows and columns count: ";
    cin >> rows >> cols;

    if (!areRowsAndColsValid(rows, cols)) {
        cout << "Invalid rows and columns count!";
        return 1;
    }

    if (!isSquareMtrx(rows, cols)) {
        cout << "Matrix is not square!";
        return 2;
    }

    int mtrx[MAX_MTRX_SIZE][MAX_MTRX_SIZE]{0};
    cout << "Enter matrix elements: ";
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cin >> mtrx[i][j];
        }
    }

    mtrxTranspose(mtrx, rows);
    mirrorLeftRight(mtrx, rows, cols); //for 270° you can use mtrxTranspose and then mirrorTopBottom
    printMtrx(mtrx, rows, cols);
}
```