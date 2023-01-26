# LOJ 1443 - Printing Divisors

## Summary
Print the divisors of a given number N in an order such that when two consecutive divisors are divided, the result is a prime number.

## Prerequisite
Prime factorization: https://cp-algorithms.com/algebra/factorization.html
(For solving this problem the basic O($\sqrt{N}$) algorithm will suffice)

## Solution
Say, N = $2^4$ * $3^2$ * $5^2$

M = $2^4$ * $3^0$ * $5^0$

Clearly M is a divisor of N and writing all the divisors of M is pretty easy:-

<span style="color:aqua">1, $2^1$, $2^2$, $2^3$, $2^4$ = M. </span>

Now, let's raise the power of 3 by 1.

M = $2^4$ * $3^1$ * $5^0$

<span style="color:aqua"> 1, $2^1$, $2^2$, $2^3$, $2^4$</span>, <span style="color:lime">$2^4$ * $3^1$ = M, $2^3$ * $3^1$, $2^2$ * $3^1$, $2^1$ * $3^1$, 1 * 3.</span>

Raising the power of 3 again by 1.

M = $2^4$ * $3^2$ * $5^0$

<span style="color:aqua"> 1, $2^1$, $2^2$, $2^3$, $2^4$</span>, <span style="color:lime">$2^4$ * $3^1$, $2^3$ * $3^1$, $2^2$ * $3^1$, $2^1$ * $3^1$, 1 * 3,</span> <span style="color:violet">1 * $3^2$, $2^1$ * $3^2$, $2^2$ * $3^2$, $2^3$ * $3^2$, $2^4$ * $3^2$ = M.</span>

Raising the power of 5 by 1.

M = $2^4$ * $3^2$ * $5^1$

<span style="color:aqua"> 1, $2^1$, $2^2$, $2^3$, $2^4$, $2^4$ * $3^1$, $2^3$ * $3^1$, $2^2$ * $3^1$, $2^1$ * $3^1$, 1 * 3, 1 * $3^2$, $2^1$ * $3^2$, $2^2$ * $3^2$, $2^3$ * $3^2$, $2^4$ * $3^2$</span>, <span style="color:lime"> $2^4$ * $3^2$ * $5^1$ = M, $2^3$ * $3^2$ * $5^1$, $2^2$ * $3^2$ * $5^1$, $2^1$ * $3^2$ * $5^1$, $3^2$ * $5^1$, $3^1$ * $5^1$, 1 * $5^1$.</span>

Now, M = N = $2^4$ * $3^2$ * $5^2$

<span style="color:aqua"> 1, $2^1$, $2^2$, $2^3$, $2^4$, $2^4$ * $3^1$, $2^3$ * $3^1$, $2^2$ * $3^1$, $2^1$ * $3^1$, 1 * 3, 1 * $3^2$, $2^1$ * $3^2$, $2^2$ * $3^2$, $2^3$ * $3^2$, $2^4$ * $3^2$</span>, <span style="color:lime"> $2^4$ * $3^2$ * $5^1$ = M, $2^3$ * $3^2$ * $5^1$, $2^2$ * $3^2$ * $5^1$, $2^1$ * $3^2$ * $5^1$, $3^2$ * $5^1$, $3^1$ * $5^1$, 1 * $5^1$,</span> <span style="color:violet"> 1 * $5^2$, $3^1$ * $5^2$, $3^2$ * $5^2$, $2^1$ * $3^2$ * $5^2$, $2^2$ * $3^2$ * $5^2$, $2^3$ * $3^2$ * $5^2$, $2^4$ * $3^2$ * $5^2$ = M.</span>

Done!

When finding the divisors of a subset of prime numbers raised to specific powers, a pattern can be observed. After finding all the divisors of the initial subset, the power of a different prime number can be increased one by one and the previous divisors (excluding the new prime number) can be multiplied by it. The order in which the divisors are multiplied by the new prime number depends on whether the power is odd or even. If the power is odd, the divisors are multiplied starting from the back of the list, and if the power is even, the divisors are multiplied starting from the beginning of the list. This pattern can be used to construct a solution. So the answer can't never be "**impossible**".

## Complexity
- Time Complexity: O(T * $\sqrt{N}$).
- Memory Complexity: O($\sqrt{N}$).

## Code

### C++

```cpp
#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;


int main(int argc, const char *argv[]) {
     
    // for fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int ts = 1; ts <= t; ++ts) {
        ll n;
        cin >> n;

        vector <ll> ans {1};
        for(ll i = 2; i*i <= n; ++i) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }

            bool flag = false; // first backward iteration because of satisfying the contraint. For first prime number it doesn't matter.
            int x = i;
            int current_size = ans.size(); // size of the divisors list not containing the prime number i
            while (cnt > 0) {
                if (flag) {
                    // forward iteration
                    for(int i = 0; i < current_size; ++i) ans.push_back(ans[i] * x);
                }
                else {
                    // backward iteration
                    for(int i = current_size-1; i >= 0; --i) ans.push_back(ans[i] * x);
                }
                flag ^= true;
                x *= i; // raising to the next power of that prime number
                cnt--;
            }
        }

        if (n > 1) {
            // a single prime factor greater than square root of that number
            for(int i = ans.size()-1; i >= 0; --i) ans.push_back(n * ans[i]);
        }

        cout << "Case " << ts << ":\n";
        for(ll x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
} 
```
