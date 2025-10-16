# Важни неща, на които да обръщате внимание: 

* <strong> Добра практика е да използвате константи </strong>

пример: Напишете програма, която приема масив с максимум 50 елемента и изведете... .

```cpp
const int MAX_ARRAY_SIZE = 50;
int array[maxArraySize];
```

* <strong> Правете валидации на входните данни </strong>

пример: Напишете програма, която приема число в интервала [10, 100] и изчислява... .

```cpp
int num = 0;
cout << "Enter a number: ";
cin >> num;

const int MIN_VALUE = 10;
const int MAX_VALUE = 100;

if (num < MIN_VALUE || num > MAX_VALUE) {
    cout << "Number is out of range!";
    return 3;
}
```

* <strong> Старайте се да не използвате странни числа (magic numbers) </strong>

```cpp
cin >> radius;
double area = 3.14159 * radius * radius; // not okay, what is that random number 3.14159

const double PI = 3.14159; // much better
double area = PI * radius * radius;
```

* <strong> Използвайте смислени имена на променливите </strong>

```cpp
bool peshoIsTheBest = true; // not okay
int sagdagsfagid = 23; // not okay

int isEven = true; // okay
int userAge = 23; // okay
```

* <strong> Кодът трябва, по възможност, да бъде разделен на функции (особено ако има повтарящ се код) </strong>
* <strong> Не използвайте string, vector, go to... </strong>
* <strong> Използвайте предимно българските термини, например: област на видимост(вместо scope), указател(вместо pointer), псевдоним(вместо reference)... </strong>