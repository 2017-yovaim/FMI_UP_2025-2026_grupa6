<h1> Функции. Задачи </h1>

<p><strong>Задача 1:</strong> Напишете собствени имплементации на следните стандартни функции: abs(), min(), max(), pow() като използвате съответно имената: myAbs(), myMin(), myMax(), myPow(). </p>

<strong>myAbs()</strong> <br>
<strong>Приема: </strong> цяло число x. <br>
<strong>Връща: </strong> абсолютната стойност на x. <br>
<strong>Пример: </strong> <br>
myAbs(-5) → 5 <br>
myAbs(7)  → 7 <br>

```cpp
int myAbs(int x) {
    //your code
}
```

<br>

<strong>myMin()</strong> <br>
<strong>Приема: </strong> две цели числа x и y. <br>
<strong>Връща: </strong> по-малкото от двете. <br>
<strong>Пример: </strong> <br>
myMin(3, 7) → 3 <br>
myMin(10, -2) → -2 <br>

```cpp
int myMin(int x, int y) {
    //your code
}
```

<br>

<strong>myMax()</strong> <br>
<strong>Приема: </strong> две цели числа x и y. <br>
<strong>Връща: </strong> по-голямото от двете. <br>
<strong>Пример: </strong> <br>
myMax(3, 7) → 7 <br>
myMax(10, -2) → 10 <br>

```cpp
int myMax(int x, int y) {
    //your code
}
```

<br>

<strong>myPow()</strong> <br>
<strong>Приема: </strong> реално число base и цяло число exp. <br>
<strong>Връща: </strong> резултата от base, повдигнато на степен exp. <br>
<strong>Забележка: </strong> Ако exp е отрицателно, резултатът е реципрочен (1 / base^|exp|). <br>
<strong>Пример: </strong> <br>
myPow(2, 3) → 8 <br>
myPow(2, -2) → 0.25 <br>
myPow(5, 0) → 1 <br>

```cpp
double myPow(double base, int exp) {
    //your code
}
```
