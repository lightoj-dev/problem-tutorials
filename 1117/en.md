# 1117 - Helping Cicada

This is a number theory problem and you have given `T` test cases and for each test cases you have `N`, a possible range, and `M` positive integer numbers, denoting the life cycles of the predators.

---

#### Summary

For the `T` group of input set, where each set consist of `N` and `M` numbers, you have to find how many of the numbers from `1 to N` can't be divided by any of given `M` numbers.

#### Solution

For any number `x`, `1 ~ n` it has `[n/x]` numbers of divisors, in a other word, there are `[n/x]` numbers that can be divisible by `x`, [a] means a is rounded down.

As now you have to deal with multiple divisors, from the (principle-of-inclusion-and-exclusion)[https://brilliant.org/wiki/principle-of-inclusion-and-exclusion-pie/] :

`AUBUC=A+B+C-A∩B-A∩C-B∩C+A∩B∩C`

If you summarize this, the pattern is you add the divisor counts of `N/LCM` of odd numbers and subtracts even.

As you have `M` divisors to deal with, if you check the binary of all the numbers from `1 ~ (2^M -1)`, you can see all possible combinations you need are presented there.

for example, let's consider sample test case 1:

```
N = 15
M = 3
{ 2,  3,  5 }
binary representation of 1 - (2^M - 1) or 7:

0001        // C     -> gets included
0010        // B     -> gets included
0011        // B∩C   -> gets excluded
0100        // A     -> gets included
0101        // A∩C   -> gets excluded
0110        // A∩B   -> gets excluded
0111        // A∩B∩C -> gets included
```

So the algorithm is:

- loop through all the numbers `1 ~ 1<<M`,
- check for the set bits, find their LCM and
- add `N/LCM` to the count if the set bit count is negative, subtract otherwise,
- print `N - count`, here `count` tracks all the number from `1-N` that can be divided at least one of the `M` numbers.

#### Code

### C++

```C++
#include "bits/stdc++.h"

using namespace std;

#define deb(x,y) cerr << #x << " " << x << " " << #y << " " << y <<endl;
#define deb1(x) cerr << #x << " " << x <<endl;
#define isSet(x,i) (bool)(x & (1<<i))

long long lcm(long long a, long long b){
    return a/__gcd(a,b) * b;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int tc,t(1);
    for(cin>>tc; tc; ++t,--tc){

        // print the test case number
        cout<<"Case "<<t<<": ";

        // input part
        long long n,m;
        cin>>n>>m;

        vector<long long>lst(m);
        for(int i=0; i<m; cin>>lst[i++]);


        long long cnt(0);

        for(int i=1; i<(1<<m); ++i){
            vector<long long>bitCount;

            // find all the set bits
            for(int j=0; j<15; ++j)
                if(isSet(i,j))
                    bitCount.push_back(lst[j]);

            long long ab=bitCount[0];

            // find LCM of all the set bits
            for(auto x: bitCount)
                ab = lcm(ab,x);

            // deb1(lst.size());

            (bitCount.size()%2?cnt+= (n/ab): cnt-=(n/ab));

            // deb(ab,cnt);

        }
        cout<<n-cnt<<endl;

    }
    return 0;
}
```
