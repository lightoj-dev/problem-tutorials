# Light oj 1259 : Goldbach's Conjecture

# Summary

*We are given `T (1 <= T <= 300)` test cases and an integer `N ( 4 <= N <= 10000000)` where N is even number. We have to find the number of ways `N` can be written as sum of two primes.*

**Category** : Number Theory

**Prerequisite** : [Sieve of Eratosthenes](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)

Goldbach's conjecture state that every even number greater than `2`  is the sum of two prime numbers. We have to find the number of ways we can express `n` as sum of two primes.

If `n` is the number and `a` and `b` are primes and `a + b = n` where `a <= b`, we have to find the number of `(a, b)` pairs.

## Approaches

***O(n<sup>2</sup>)* approach:** We can choose all possible prime pairs and check if there sum is `n` or not. But the value of `n` is quite big so we will get a TLE applying this process.

***O(n)* approach :** We will iterate through a array of prime numbers where `a = prime[i]` and check whether  `b = n – a` is a prime or not. If `b` is a prime then we count this `(a, b)` pair and move to the next index.

## Explanation

If `n` = `22`:

Let's consider the array `primes` containing a lot of prime numbers: `{2, 3, 5, 7, 11, 13, 19, ...}`

At first index `a` = `primes[1]` = `2` and `b` = `22` – `2` = `20` ; where `b` is not a prime.

Move to the next index `a` = `primes[2]` = `3` and `b` = `22` – `3` = `19` where `b` is a prime, so `(3, 19)` is a possible answer.

Next `a` = `primes[3]` = `5` and `b` = `22` – `5` = `17` where `b` is a prime, so `(5, 17)` is a possible answer.

Next `a` = `primes[4]` = `7` and `b` = `22` – `7` = `15` where `b` is not a prime.

Next `a` = `primes[5]` = `11`  and `b` = `22` – `11` = `11` where `b` is a prime, so `(11, 11)` is a possible answer.

If we iterate for the value of `primes[i]` more than `n / 2` then we will get `a > b` which is against our given condition. That’s why we have to stop our iteration at that position.

So here we get `3` prime pairs `(3, 19), (5, 17), (11, 11).`

## C++ code
```C++

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mx 10000003
bitset <mx> mark;
vector <ll> primes;

void sieve() {
    mark[0] = mark[1] = 1;
    primes.push_back(2);
    int lim = sqrt(mx * 1.0) + 2;
    for (int i = 4; i < mx; i += 2) mark[i] = 1;
    for (int i = 3; i < mx; i += 2) {
        if (!mark[i]) {
            primes.push_back(i);
            if (i <= lim)
                for (int j = i * i; j < mx; j += i)
                    mark[j] = 1;
        }
    }
}

int main() {
    sieve();
    ll t; scanf("%lld", &t);
    ll f = 0;

    while(t--) {
        f++;
        printf("Case %lld: ", f);
        ll n; scanf("%lld", &n);
        ll ans = 0;

        for(ll i = 0; primes[i] <= (n / 2); i++) {
            ll p = n - primes[i];
            ll q = primes[i];
            if(!mark[p] && !mark[q]) {
                ans++;
            }
        }

        printf("%lld\n", ans);
    }
}
```