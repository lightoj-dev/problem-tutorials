# LOJ 1102 - Problem Makes Problem

In this problem, you will be given `T` testcases. The first line of each test case contains two integers `n` and `k`. We have to find the number of ways we can add `k` number of  variables so that their sum is equivalent to `n`.

To be more precise, suppose `n=4` and `k=3`, we have to find the number of ways to assign non-negative integer values to `x1, x2, x3, x4` such that `x1 + x2 + x3 = 4`.



### Approach:
In order to solve this problem, there are a few prerequisites that need to be fulfilled which are: you need to have a basic understanding of combinatorics and inverse modulo. The tutorials are given below in the "Resources" section.

So having a clear concept of the topics above, we can solve this problem. Now let's think about the test case `n=4, k=3`. Let's imagine there are 4 stars * * * * and now we have to divide these 4 stars into 3 subsegments so that summation of stars in all the `k` subsegments is equivalent to 4.
To be more clear, notice in the diagram `* | * * | * ` where we seperated the 4 stars into 3 subsegments using two bars. Now in the first segment we have `x1=1`, and in the second segment we have `x2=2` and lastly `x3=1` which is equivalent to 4. Now since our particular subsegment can have zero stars as well,  so `| * * | * *` can also be true where `x1=0`,`x2=2` and `x3=2`.

So let's imagine we are given an array of size `n+k-1` which is filled with with n stars and k-1 bars. Now we have to find the number of ways we can arrange these `(k-1)` bars within the `n+k-1` sized array so that we have `k` subsegments whose summation is equivalent to `n`.
If you know combinatorics, you can easily tell the answer to this problem which is `(n+k-1)c(k-1)` where `n+k-1` is the summation of stars(n) and bars(k-1) and bars can be arranged among `n+k-1` characters in `(n+k-1)c(k-1)` ways. If you don't know how to calculate this, you can always check the code or tutorials given below.

This concept also coincides with the famous "Stars and Bars Method". Link to have a deep understanding is given in the bottom.

__Notes:__ We have to find the factorials upto `2*10^6` even though the constraint of this problem for both `n` and `k` is `1*10^6` only. Also we need to compute the problem using `long long` because there is a chance that multiplication of two numbers while finding the answer can surpass `int` limits.



### Resources:
Here are some resources of  **inverse modulo and combinatorics** so that you can have a deeper understanding and learn to solve problems using these resources:-

- [Shafaetsplanet](https://www.shafaetsplanet.com/?p=600) **(Combinatorics)**
- [Go code](https://www.youtube.com/watch?v=aGjfSTr_0AE) **(Inverse Mod Demonstration)**
- [Bangladesh Advanced Computing Society - BACS](https://www.youtube.com/watch?v=ZsZglqx33U8&t=13737s) **(Inverse Mod and some advanced problem applications)**
- [CP-AlGORITHM](https://cp-algorithms.com/algebra/module-inverse.html) **(inverse Mod and Fermat's Little Theorem)**
- [Bangladesh Advanced Computing Society - BACS](https://www.youtube.com/watch?v=fEb_swNH0fY)   **(Stars and Bars Method)**


### C++ Implementation:
```
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define MOD 1000000007

int modPow(int b, int p)
{
    int r = 1;
    while(p)
    {
        if(p&1)
            r = (r*b)%MOD;
        b = (b*b)%MOD;
        p >>= 1;
    }
    return r;
}

int fact[2000009];
void factorial()
{
    fact[0]=1;
    for(int i=1; i<2000002; i++)
    {
        fact[i]=(fact[i-1]%MOD*i)%MOD;
    }
}

main()
{
    int t;
    factorial();    // generating factorial upto 2*10^6 since we are trying to find 
                    // factorial of n+k-1 where in worst case n=10^6 and k=10^6 ans so n+k=2*10^6
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n,k;
        cin>>n>>k;
        int ans=fact[n+k-1];    //bars can be like this | * * | * * which means 0 2 2 ==4 so the 
                                // ways we can arrange  these 2 bars to make 3 segments so that 
                                // their summation is n is the formula
        int r=(fact[n]*fact[k-1])%MOD;   //fact[n+k-1-(k-1)]==fact[n] 
                                         // n+k-1 c r-1 means there are  6 characters and how 
                                         // many ways we can put the 2 bars among these 6 characters
        ans=(ans*modPow(r,MOD-2));
        cout<<"Case "<<i<<": "<<ans%MOD<<endl;
    }
}
```
