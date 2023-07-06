## Dimik Even or Odd 2

### What the problem Wants
In this problem, you will be given `T` testcases.Each line of the testcase consist of an integer `n`.We have to determine whether `n` is even or odd. The difference from dimik even odd 1 is that the number can have upto 100 digits which won't fit in long long data type of C++. 

### Approach 
- Take Input as a string so that it can take upto 100 digits 
- Check the last digit of that string 
- If its divisible by 2 then print 'even' otherwise print 'odd' 

### Solution in C++

> Step 1: Include necessary libraries

```cpp
#include<bits/stdc++.h>
using namespace std;
```

The bits/stdc++.h library is included, which is a header file that includes all the standard libraries in C++.

### Define the function to check if a number is even

```cpp
bool isEven(string number) {
    int lastDigit = number[number.size() - 1] - '0';
    return (lastDigit % 2 == 0);
}
```

> Step 2: Function for identify Odd Even

- Inside the isEven function, we extract the last digit of the number by accessing the last character of the string (number[number.size() - 1]) and subtracting the ASCII value of '0' from it. This converts the character representation of the digit to an integer.

- We then check if the last digit is divisible by 2 using the modulo operator (%). If the remainder is 0, the number is even and we return true; otherwise, we return false

> Step 3: Use the function from main 

### Implement the main function
```cpp
int main() {
    int numTestCases;
    cin >> numTestCases;
    cin.ignore(); // Ignore the newline character after numTestCases

    for (int i = 0; i < numTestCases; i++) {
        string number;
        getline(cin, number);
        if (isEven(number)) {
            cout << "even" << endl;
        } else {
            cout << "odd" << endl;
        }
    }

    return 0;
}
```

- In the main function, we first read the number of test cases from the input using cin >> numTestCases.

- Since we read an integer before reading strings, we need to ignore the newline character left in the input buffer. We do this using cin.ignore().

- Next, we enter a loop to process each test case. For each test case, we read the number as a string using getline(cin, number). This allows us to handle numbers with multiple digits.

- We then call the isEven function with the number as the argument. Depending on the return value, we output whether the number is even or odd using cout.

### Full code 
```cpp
#include<bits/stdc++.h>
using namespace std;

bool isEven(string number) {
    int lastDigit = number[number.size() - 1] - '0';
    return (lastDigit % 2 == 0);
}

int main() {
    int numTestCases;
    cin >> numTestCases;
    cin.ignore(); // Ignore the newline character after numTestCases

    for (int i = 0; i < numTestCases; i++) {
        string number;
        getline(cin, number);
        if (isEven(number)) {
            cout << "even" << endl;
        } else {
            cout << "odd" << endl;
        }
    }

    return 0;
}
```

### Solution in python 

As python can take upto 100 digit as input we will just check if its even or odd by just dividing it by 2

```py
testCase=eval(input())   # taking test case and eval converting it to int
for i in range(testCase):  # for each test case
    num=eval(input())  # take the numnber and convert it to int
    if(num%2==0):   # check even or odd
        print('even')
    else:
        print('odd')
```