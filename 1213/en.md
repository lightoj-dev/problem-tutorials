# LOJ 1213 - Fantasy of a Summation

In this problem, you will be given `T` testcases. The first line of each test case contains three integers `n` ,`k` and `MOD` where `n` denotes the number of elements of the array, `k` denotes the number of nested loops and `MOD` denotes the number used for modulus operation over the summation of the elements of the array.
The next line consists of elements of the array.Now, in the problems statement it was told to design an algorithm,which is more efficient than the algorithm given in the problem statement whose time complexity is `n^k`


### Approach:
In order to solve this problem, there are a few prerequisites that need to be fulfilled which are: you need to have a basic understanding of Modular Arithmetic.The tutorials are given below in the "Resources" section.

So having a clear concept of the topic mentioned above, we can solve this problem.

res = ( res + A[i1] + A[i2] + ... + A[iK] ) % MOD;

It has been executed for n^k times, and k numbers are added each time, so a total of k * n^k numbers will be added
At the same time, we can also find that the number of times each elements of the array which is added into the `res` variable is same.Then each number is added for (k * n^k) / n = k * n^(k-1) times

So,
```
sum = a1 * k * n^(k-1) + a2 * k * n^(k-1) + …… + a * n * k * n^(k-1) 

= (a1+a2+……+an) * k * n^(k-1) = sum * k * n^(k-1)
```
Then we use modular exponentiation to compute the value of n^(k-1).
Note that we need to take the modulus in each and every steps, and also take the modulus when summing the sum.

### Resources:
Here are some resources of **Modular Arithmetic** so that you can have a deeper understanding on these topics and learn to solve problems using these resources:
- [GeeksforGeeks](https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/)(Modular Exponentiation)
- [Khan Academy](https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/modular-addition-and-subtraction)(Modular Addition and Subtraction)
- [Khan Academy](https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/modular-multiplication)(Modular Multiplication)

If you are still stuck with this problem, check the code below:

### C++
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int modular_exponentiation(int b, int p,int mod)
{
    int r = 1;
    while(p)
    {
        if(p&1)
            r = (r*b)%mod;
        b = (b*b)%mod;
        p >>= 1;
    }
    return r;
}
main()
{
    int t;
    cin>>t;
    for(int j=1; j<=t; j++)
    {
        int n,k,mod;
        cin>>n>>k>>mod;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            sum+=x;
            sum=(sum+mod)%mod;
        }
        sum=(sum*(k%mod))%mod;
        sum=sum*modular_exponentiation(n,k-1,mod);
        cout<<"Case "<<j<<": "<<(sum+mod)%mod<<endl;
    }
}
```
