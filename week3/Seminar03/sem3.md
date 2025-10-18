#  Задачи за дати и числа на C++

## Задача 1

**Условие:**  
Да се напише програма, или извън окръжността която по зададен месец (с номер) дава броя на дните му. (нека Февруари има 28 дена)

## Пример

**Вход 1:**
<pre>3 </pre>
**Изход:**
<pre>31</pre>

**Вход 2:**
<pre>2</pre>
**Изход:**
<pre>28</pre>

**Вход 3:**
<pre>4</pre>
**Изход:**
<pre>30</pre>


### 💻 Решение 

```cpp
#include <iostream>

using namespace std;

int main()
{
    int month;
    cin >> month;
    
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            cout << 31 << endl;
            break;
        case 2:	
            cout << 28 << endl;
            break;
        case 4: case 6: case 9: case 11:
            cout << 30 << endl;
            break;
        default: 
            cout << "Invalid month!\n";
            break;
    }

    return 0;
}
```


# Задача 2 

**Условие:**  
Да се напише програма, която по зададена дата и брой дни n, получава нова дата, която ще е n дена след дадената.

## Пример

**Вход 1:**
<pre>
  Enter day, month, year: 28 2 2024
  Enter number of days to add: 5
</pre>
**Изход:**
<pre>New date: 4 3 2024</pre>

**Вход 2:**
<pre>
  Enter day, month, year: 23 4 2027
  Enter number of days to add: 10
</pre>
**Изход:**
<pre>New date: 3 5 2027</pre>

**Вход 3:**
<pre>
  Enter day, month, year: 23 4 2027
  Enter number of days to add: 500
</pre>
**Изход:**
<pre>New date: 4 9 2028</pre>


### 💻 Решение 

```cpp
#include <iostream>
using namespace std;


int main() {
    int day, month, year, n;
    
    cout << "Enter day, month, year: ";
    cin >> day >> month >> year;

    cout << "Enter number of days to add: ";
    cin >> n;

    while (n > 0) {
        int daysInCurrentMonth;
        switch (month) {
			case 1: case 3: case 5: case 7:	case 8: case 10: case 12:
				daysInCurrentMonth = 31;
				break;
			case 4: case 6: case 9: case 11:
				daysInCurrentMonth = 30;
				break;
			case 2:
				daysInCurrentMonth = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28;
				break;
			default:
				daysInCurrentMonth = 0; // Грешен месец
		}

        if (day + n <= daysInCurrentMonth) {
            day += n;
            n = 0;
        } else {
            // Изваждаме оставащите дни до края на месеца
            n -= (daysInCurrentMonth - day + 1);
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    cout << "New date: " << day << " " << month << " " << year << endl;
    return 0;
}

```


# Задача 3 

**Условие:**  
Да се напише програма, която по  дадени естествените числа n и m намира и извежда стойността на произведението: **n(n+1)(n+2)... m**
 - Вход: две естествени числа **n** и **m**, където **n <= m**
 - Изход: стойността на произведението   
 - Пример: 
    Ако **n = 3**, **m = 6**, тогава: **P=3⋅4⋅5⋅6=360**
---

## Пример

**Вход 1:**
<pre>3 6 </pre>
**Изход:**
<pre>360</pre>


### 💻 Решение 

```cpp
#include <iostream>

int main() {
    int n, m;

    std::cin >> n >> m;

    int product = 1;
    for (int i = n; i <= m; i++) {
        product *= i;
    }

    std::cout << product << "\n";
}

```
