# LOJ 1161 - Extreme GCD

## Summary
The problem is asking for the number of ways to choose four positive integers, which may or may not be distinct, from a given set of N positive integers, such that their greatest common divisor (GCD) is 1.

## Prerequisite
i) Basic Permutation and Combination. 

ii) Finding divisors of an integer N in O( $\sqrt{N}$ ) complexity.

## Solution
Let's generalize the problem a bit. We define:

**div_cnt[i]** = how many of those N numbers have a divisor equal to **i**.

**ans[k]** = number of ways choosing **4** integers from the set of N numbers such that their gcd is **equal to k**.

Now in order for having gcd equal to **k** those 4 numbers must have **k** as their common divisor but not a multiple of **k** (greater than **k**) as in that case gcd will not be equal to **k** (will be a multiple of **k** greater than **k** itself). If we set **ans[k]** = **nC4**( **div_cnt[k]** ) then we would have wronged ourselvs, because **ans[k]** will going to count some selections where gcd of those 4 numbers is a multiple of **k** but not **k**. So in this scenario we have to substract all **ans[k*i]** (i > 1) from **ans[k]** so that the **ans[k]** will be the required answer. Having discussed the solution we are bound to calculate the **ans** array in decreasing order as every **ans[i]** depends on the multiples of **i**.

## Complexity
- Time Complexity: O(T * N * $log{_2}{N}$ ).
- Memory Complexity: O(N).

## Code

### C++

```cpp
#include <bits/stdc++.h>
 
using namespace std;


typedef long long ll;


const int MAXN = 1e4;

inline ll nC4(ll n) {
    return (n*(n-1)*(n-2)*(n-3)) / 24;
}

int main(int argc, const char *argv[]) {

    // for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int ts = 1; ts <= t; ++ts) {
		int n;
        cin >> n;

        vector <int> div_cnt(MAXN+1);
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            for(int j = 1; j*j <= x; ++j) {
                if (x % j) continue;
                div_cnt[j]++;
                if (j*j != x) div_cnt[x/j]++;
            }
        }

        vector <ll> ans(MAXN+1);
        for(int i = MAXN; i >= 1; --i) {
            ans[i] = nC4(div_cnt[i]);
            for(int j = i+i; j <= MAXN; j += i) {
                ans[i] -= ans[j];
            }
        }

        cout << "Case " << ts << ": " << ans[1] << '\n';
	}

    return 0;
} 
```
