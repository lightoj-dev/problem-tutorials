# Dimik - Square Number

You have to write a program to find out whether a number is a perfect square or not.

### Solution
* Store the square root of the number in a variable
* check if the multiplication of that variable is equal to input the number

# C++
```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int test_case;
    cin >> test_case;

    for (int i = 1; i <= test_case; i++)
    {
        int num;
        cin >> num;
        int a = sqrt(num);
        if (a * a == num)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
```