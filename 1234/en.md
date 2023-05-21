# LOJ 1234 - Harmonic Number

## Solution
From the definition of H<sub>n</sub> we perceive: **H<sub>n+1</sub> = H<sub>n</sub> + (1/ n)**

So we need not to calculate **H<sub>n</sub>** using the straighforward formula for every single test case. We go from non-decreasing order of test cases whilst keeping a variable for harmonic sum so far. This way not only we save time but memory as well, because there's no need for storing all the harmonic values beforehand.

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
