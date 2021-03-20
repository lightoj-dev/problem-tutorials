# LightOJ 1289 - LCM from 1 to n

*You are given `T` test cases, for each test case you are given `n`.*

*You have to find `lcm(1, 2,...,n)` where lcm refers to the least common multiple of some integers, i.e. the smallest integer that is a multiple of all of the given integers (modulo 2^32).*

---

## Summary

*lcm(b<sub>1</sub>, b<sub>2</sub>, ... , b<sub>m</sub>)* can be represented as *p<sub>1</sub><sup>a<sub>1</sub></sup> . p<sub>2</sub><sup>a<sub>2</sub></sup> . ... . p<sub>k</sub><sup>a<sub>k</sub></sup>* where *p<sub>1</sub>, p<sub>2</sub>, ... , p<sub>k</sub>* are prime factors of those numbers and *a<sub>1</sub>, a<sub>2</sub>, ... , a<sub>k</sub>* are the maximum powers of those corresponding primes, that occur in the numbers *b<sub>1</sub>, b<sub>2</sub>, ... , b<sub>k</sub>* . This **number theory** problem requires you to find the prime factors and their corresponding powers and the product of these.

In this problem, you can assume *b<sub>1</sub>, b<sub>2</sub>, ... , b<sub>m</sub> = 1,2, ... , n* .

## Solution

### Naive Approach
Let's calculate for each prime (until *n*) the maximum power *a* of this prime *p*, so that *p<sup>a</sup> <= n*. For example, if *n = 100*, prime *5* has highest power of *log<sub>5</sub>100*, i.e. the maximum number of time we can divide *100* by *5*, which is *2*. You can see, *5<sup>2</sup> = 25* which is less than *100*, and *5<sup>3</sup> = 125* which is greater than *100*. So here, for *n = 100*, *p = 5* we get *a = 2*.

So, for each prime *p<sub>i</sub>* until *n*, we calculate *a<sub>i</sub>* , which is the maximum power of that prme till *n*. Then, *lcm =  p<sub>1</sub><sup>a<sub>1</sub></sup> . p<sub>2</sub><sup>a<sub>2</sub></sup> . ... . p<sub>k</sub><sup>a<sub>k</sub></sup>* , which is the required answer.

#### Problem with Naive Solution
*n* can be equal to *10<sup>8*, and *T* can be equal to *10<sup>4</sup>* . There are roughly *k = 6x10<sup>6</sup>* primes till  *10<sup>8* . So for each case, if we intend to use the naive solution, the complexity for each case would be *O(k log n)*, where *k* is the number of prime factors till *n*. So, total complexity will be *O(Tk log n)* , which won't pass the time limit of  4s.

### Observations

- Every prime not greater than *n* appears in the LCM at least once, i.e. *a<sub>i</sub>* is at least *1*.

**Why:** Since *p<sub>i</sub> <= n*, when we calculate *lcm(1, 2, 3, ... , n)*,  *p<sub>i</sub>* is included in *1, 2, 3, ..., n* . So it appears atleast once in the LCM.

- No prime greater than *n* will appear in the LCM.

**Why:** Let *p<sub>i</sub> > n* is a prime. There is no multiple of *p<sub>i</sub>* that is included in *1, 2, 3, ... , n* since the lowest multiple of *p<sub>i</sub>* is *p<sub>i</sub>* itself, which is greater than *n*.

- Every prime till *n* and not greater than *sqrt(n)* will appear atleast twice in the LCM.

**Why:** Let *p<sub>i</sub> <= sqrt(n)* be a prime not greater than *n*. Let *p<sub>i</sub><sup>a<sub>i</sub></sup>* appear in the prime. Since *p<sub>i</sub> <= sqrt(n)*, *p<sub>i</sub><sup>2</sup> <= n*, so *a<sub>i</sub>* is at least 2.

- Every prime till *n* and greater than *sqrt(n)* will apear exactly once in the LCM.

**Why:** Let *p<sub>i</sub> > sqrt(n)*  be a prime not greater than *n*. Let *p<sub>i</sub><sup>a<sub>i</sub></sup>* appear in the prime. Now, *p<sub>i</sub> > sqrt(n)* implies that *p<sub>i</sub><sup>2</sup> > n*, so *a<sub>i</sub>* can not be greater than *1*. And, according to the first observation, *a<sub>i</sub>* is at least *1*. So, *a<sub>i</sub>* is exactly *1*, which means *p<sub>i</sub>* appears exactly once in the LCM.

These observation paves the way for some workarounds and optimizations that gives a faster approach.

### Faster Approach

- If we know the product of all primes till *n*, we can consider this product as "taking each prime till *n* atleast once" for the LCM. So we can precalculate this before processing any of the test cases, for all possible *n* using techniques like cumulative sum (here we can call it cumulative product).

- For each case, we can find the product of primes till *n* using a binary search. Taking this product implies we took all the primes till *n* at least once. So, we don't need to consider primes greater than *sqrt(n)* according to the fourth observation.

- Now we can only consider primes till *sqrt(n)*. If any prime *p<sub>i</sub>* appears *a<sub>i</sub>* times in *n*, we multiply *p<sub>i</sub>* , *a<sub>i</sub> - 1* times with the answer (since we already took these primes once in the previous step).

- Done!

The preprocessing needs *O(n)* operations to complete, for just once, since we are just running a loop till the max value of *n*.

For each case, we are considering all primes till *sqrt(n)* and checking how many times they appear till *n*. This requires *O(sqrt(n) * log2(n))* operations at most.

So, total complexity for *T* cases = *O(n + T * sqrt(n) * log2(n))* , which passes the 4s time limit.

## C++ code

```cpp
#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using uint = unsigned int;

//storing the values in unsigned int
//since it prevents exceeding memory limit
//also, it automatically makes the numbers
//modulo 2^32

const int mx = 1e8 + 9; //max value of n
const int mxprm = 6e6 + 9; //max number of primes

int psz = 0; //keeping count the number of primes discovered

bitset <mx> mark; //to keep track of primes
uint primes[mxprm]; //to store the primes
uint mul[mxprm];  //to store the cumulative product of the primes

void sieve() { //just a prime sieve code
    mark[0] = mark[1] = 1;
    primes[psz++] = 2;
    int lim = sqrt(mx * 1.0) + 2;
    for (int i = 4; i < mx; i += 2) mark[i] = 1;
    for (int i = 3; i < mx; i += 2) {
        if (!mark[i]) {
            primes[psz++] = i;
            if (i <= lim)
                for (int j = i * i; j < mx; j += i)
                    mark[j] = 1;
        }
    }
}

int main() {
    sieve();

    mul[0] = 2; //first prime is 2, so cumulative product till first prime is 2
    for (int i = 1; i < psz; i++)
        mul[i] = (primes[i] * mul[i - 1]); //calculating cumulative product

    int tc; scanf("%d", &tc);
    int kase = 0;
    while (tc--) {
        int n; scanf("%d", &n);
        printf("Case %d: ", ++kase);

        uint ans = 1;

        int idx =  upper_bound(primes, primes + psz, n) - primes;
        //upper_bound gives the iterator to the smallest prime greater than n
        //idx contains it's index

        idx--; //now, idx contains the index of the largest prime not greater than n

        ans *= mul[idx];
        for (int i = 0; i < psz; i++) {
            ll p = primes[i];
            ll x = n;
            ll a = 0;

            if (p * p > n) break; //checking primes till sqrt(n) is enough

            //for each prime p, let's find the maximum power of p till n
            //stored in the variable a
            while (x >= p) {
                x /= p;
                a++;
            }

            ans *= pow(p, a - 1); //multiplying by p^(a-1) since we took these primes once before
        }

        //answer is already calculated modulo 2^32 because of taking unsigned integer
        printf("%lld\n", ans);
    }
}
```