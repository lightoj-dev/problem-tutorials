# LOJ 1007 - Mathematically Hard

_You have given `T` test cases and for each test case you have `a`, the lower bound, and `b`, the upper bound, find the summation of the
scores of the numbers from a to b (inclusive), where <br>
score (x) = n<sup>2</sup>,where n is the number of relatively prime numbers with x, which are smaller than x._

---

### Summary

This is a number theory problem and for the `T` group of the input set, where each set consists of `a` and `b`, you have to find,square sum of all Euler function values from `a` to `b`.

### Solution

Before you get to the solution let's have some idea about `Euler's totient function` aka `phi`.<br>

```
Euler's totient function, also known as phi-function `ϕ(n)`, counts the number of integers between `1` and `n` inclusive, which are `coprime` to `n`. Two numbers are coprime if their greatest common divisor equals `1` (`1` is considered to be coprime to any number).
```

Have a look:

- [wikipedia: Euler's totient function](https://en.wikipedia.org/wiki/Euler%27s_totient_function)
- [cp-algorithms: Euler's totient function](https://cp-algorithms.com/algebra/phi-function.html)

- [A quite useful cheat-sheet of CP: Phi Implementation](https://github.com/ar-pavel/CP-CheatSheet#631-euler-function)

Using Euler's totient function, calculate number of coprime for all the numbers until max possible input. Now, let's assume you have `phi[]` array that contains all the `ϕ(n)` values. As you will need to print the sum of square values of the `ϕ(n)`, loop through the `phi[]` array and multiply them with own value (`phi[i] = phi[i]*phi[i]`). Now your `phi[]` array contains square values of each `ϕ(n)`. For each query, as you need to print `sum(phi[a] ... phi[b])`, you can optimize this process by generating a [cumulative sum array](https://www.tutorialspoint.com/cplusplus-program-for-range-sum-queries-without-updates) of of `phi[]`.

The algorithm is:

- find all Phi values from `1 - rangeMax`
- calculate square value of each of them
- generate cumulative sum array of squared phi values
- for each query, print the `cumulative sum array[b]` - `cumulative sum array [a-1]`

### C++
-----
```cpp
#include <bits/stdc++.h>

using namespace std;

#define M 5000000

int phi[M+2];
unsigned long long phiSum[M+2];

void calculatePhi(){
    for(int i=2; i<=M; i++)
        phi[i] = i;
    for(int i =2; i<=M; i++)
        if(phi[i]==i)
            for(int j=i; j<=M; j+=i)
                phi[j]-=phi[j]/i;
}

int main(){

    calculatePhi();
    phiSum[1] = 0;

    for(int i=2; i<=M; i++)
        phiSum[i]= ((unsigned long long)phi[i]* (unsigned long long)phi[i])+phiSum[i-1];

    // for(int i=1; i<10; ++i)
    //  cout<<phi[i]<<" "<<phiSum[i]<<endl;
    // deb(phi[2]);
    // deb(phiSum[20]);

    int tc,t(1);
    for(scanf("%d",&tc); tc; ++t,--tc){
        int a,b;
        scanf("%d%d",&a,&b);
        unsigned long long x = phiSum[b]-phiSum[a-1];
        printf("Case %d: %llu\n",t,x);
    }
    return 0;
}
```
