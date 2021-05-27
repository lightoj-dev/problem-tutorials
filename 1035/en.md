# Lightoj 1035 : Intelligent Factorial Factorization	

## Summary

*We are given T (T <= 125) test cases and an integer N ( 2 <= N <= 100 ). We have to find all the prime factors of N!.*

*To solve that problem we need to learn :*

1. [Sieve of Eratosthenes](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)

2. [Prime factorization](https://forthright48.com/prime-factorization-of-integer)
3. [vector]( https://youtu.be/W1McvE4a910) 

Since `N <= 100`, `N!` can be quite big, so  that it may not fit in 64-bit long long integer types. So we can’t just calculate it using formula `N! = N * (N  - 1) * (N – 2) * (N – 3) * …….* 2 * 1.`

For this problem we need to first store the prime factors of `(N – 1)!` then add it with the prime factors of `N` in this way we can easily get all the prime factors of `N!` .  Since `N! = N * (N - 1)!`.

## Explanation

The prime factorization of `2!`, `3!` and `4!` are given below:

*2! = 2* 

Prime factors of *2 = 2<sup>1</sup> = 2!*

Prime factors of *3 = 3<sup>1</sup>*

To find the prime factor of *3!* w
e have to add the prime factors of *2!* and *3*:

Here, *N = 3* and *N - 1 = 2!*

So *3! = 3 x 2! = (3<sup>1</sup>) x (2<sup>1</sup>)  = 6*

Prime factors of *4 = 2<sup>2</sup>*

To find the prime factors of *4!*  we have to add the prime factors of *3!* and *4*

Here *N = 4* and *N – 1 = 3!*  

So, *4! = 4 x 3! = (2<sup>2</sup>) x (3<sup>1</sup> x 2<sup>1</sup>) = 2<sup>(2 + 1)</sup> x 3<sup>1</sup> = 2<sup>3</sup> x 3<sup>1</sup> = 24*

Thus we get all the prime factors of *N!*



## Solution

Firstly, we have to store all the prime numbers up-to 100. Then we need to calculate all the prime factors of numbers between 1 to 100 and store them in a vector pair. Then we will add the prime factors of n with the prime factors of (n – 1)!. Then we store the ans in a vector pair and thus we get our required ans.

## C++ code
```C++

#include<bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0);cin.tie(NULL);
#define endl '\n';
#define mx 105

typedef long long ll;
typedef pair<ll, ll>  pll;

bitset<mx>mark;

vector<ll>primes;
vector<vector<pll>>p_facto(mx);
vector<vector<pll>>ans(mx);

ll cnt[mx];


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
    FIO;
    sieve();

    for(ll i = 2; i <= 100; i++) {   // "prime factorization"
        ll n = i; 
        for(auto j : primes) {
            if(j * j > n) break;
            if(n % j != 0) continue;
            ll a = 0;
            while(n % j == 0) {
                n = n / j;
                a++;
            }
            p_facto[i].push_back({j, a});
        }

        if(n > 1) p_facto[i].push_back({n, 1});
    }



    for(ll i = 0; i < p_facto.size(); i++) {
        vector<pll>v;

        for(ll j = 0; j < p_facto[i].size(); j++) {
            v.push_back({p_facto[i][j].first, p_facto[i][j].second});  // storing i's prime factors in v
        }

        for(ll j = 0; j < v.size(); j++) {
            cnt[v[j].first] += v[j].second;    // we already have (i - 1)! 's prime factors
        }                                      // now just add i's prime factors, since  i ! = i * (i - 1)!

        for(ll j = 0; j < mx; j++) {
            if(cnt[j] != 0) {
                ans[i].push_back({j, cnt[j]});   //storing ans
            }
        }
    }

    ll t; cin >> t;
    ll f = 0;

    while(t--) {
        cout << "Case " << ++f << ": ";

        ll n; cin >> n;

        cout << n << " = ";

        for(ll j = 0; j < ans[n].size(); j++) {
                
            cout << ans[n][j].first << " " << "(" << ans[n][j].second << ")";
            
            if(j != ans[n].size() - 1) {
                cout << " * ";
            }
        }
        cout << '\n';

    }

    return 0;

}
```