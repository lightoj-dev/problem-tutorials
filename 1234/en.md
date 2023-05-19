# LOJ 1234 - Harmonic Number

## Solution
Instead of Brute-forcing for every individual test case, we go from lower bound (**1**) to the upper bound (**1e8**). Along the way we calculate the harmonic sum so far and any test case equal to the number we are at, assign the harmonic sum to the answer of that individual test case.

## Complexity
- Time Complexity: O($T$). 
- Memory Complexity: O($T$).

## Code

### C++

```cpp
#include <bits/stdc++.h>

using namespace std;


typedef pair <int, int> pii;


int main() {
    
    // For fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXN = 1e8;

    int t;
    cin >> t;

    // 1-based indexing
    vector <pii> N(t+1);
    for(int i = 1; i <= t; ++i) {
        cin >> N[i].first;
        // Saving corresponding index of the test case
        N[i].second = i;
    }
    sort(N.begin(), N.end());

    vector <double> ans(t+1);
    double now = 0;
    int idx = 1;
    for(int i = 1; i <= MAXN; ++i) {
        now += 1. / i;
        while (idx < (int)N.size() && N[idx].first == i) { // Could be duplicates, that's why using 'while' loop
            ans[N[idx++].second] = now;
        }
    }

    for(int ts = 1; ts <= t; ++ts) {
        cout << fixed << setprecision(10) << "Case " << ts << ": " << ans[ts] << '\n';
    }

    return 0;
}
```