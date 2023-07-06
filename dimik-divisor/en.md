## Dimik Divisor 

### What the problem wants 

Basically you will be given a number you need to find all the divisor from it 

You can find more about divisors [here](https://www.splashlearn.com/math-vocabulary/division/divisor)

### Solution 

The most basic way to solve this is as following 

- Start a loop from 1 to N , Where N is the number given
- Check if the any number can divide N with a remainder of 0 
``` 6 % 3 == 0 ``` That means the remainder of 6 after dividing it by 3 is 0
- You can print them as they are the divisor 
> Be careful about newline and extra space. If you are stuck with that problem see the code to know how to handle it

### CPP Code 

```cpp

#include<bits/stdc++.h>  // includes necessary library
using namespace std;
#define ll long long int
int main()
{
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        int num;
        cin>>num;
        cout<<"Case "<<t<<": ";  // printing Case numbers
        for(int i=1;i<num;i++)
        {
            if(num%i==0)
            {
                cout<<i<<" ";
            }
        }
        cout<<num<<endl;   // the last divisor will be the number itself
    }
    return 0;
}

```

### Efficiency 

This solution can be optimized 

Here is an observation 

When we look for divisors of a number, they always come in pairs. For example, consider the number 36. The divisors of 36 are: 1 and 36, 2 and 18, 3 and 12, 4 and 9, 6 and 6. Notice that the pairs are formed symmetrically around the square root of the number (6 in this case).

By iterating up to the square root of the number, we ensure that we cover all possible divisors without redundant checks. If we go beyond the square root, we would end up checking the same pairs of divisors in reverse order. This would not yield any new divisors and would waste computational resources.

Therefore, by limiting the iteration to the square root of the number, we optimize the algorithm by avoiding unnecessary iterations and improve its efficiency.

Note that if a number is a perfect square (e.g., 9, 16, 25), the square root will be one of the divisors, and it will be added to the list twice in the algorithm implementation (once in the iteration and once in the check for the division result).

So to find divisors of a number the following algorithm can be followed

- Start with an empty list to store the divisors.
- Input the number for which you want to find the divisors.
- Find the square root of the input number and store it in a variable, let's say sqrtNum. This will be the upper limit for the iteration.
Iterate from 1 to sqrtNum (inclusive):
- For each iteration:
   - a. Check if the current iteration value (i) is a divisor of the input number.
   - b. To check if i is a divisor, calculate the remainder of the division of the input number by i. If the remainder is 0, then i is a divisor.
   - c. If i is a divisor, add it to the list of divisors.
   - d. Check if i is different from the division result of the input number by i. If they are different, it means there is another divisor (num / i). In that case, add the division result to the list of divisors as well.
Return the list of divisors.