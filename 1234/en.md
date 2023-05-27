# LOJ 1234 - Harmonic Number

## Solution
We won't be able to iterate from 1 to n for each test-case independently, since it will not fit the time limit. What we can do is iterate once from `n=1` to `1e8` (max) and compute `H(n)` for each of them using `H(n) = H(n-1) + 1/n`. Whenever we come across a `n` that is queried in the input, we will save the value for output. After the iteration has been completed, we will output all the queries together.

### Complexity
- Time Complexity: `O(MAX(N))`. 
- Memory Complexity: `O(T)`.

## C++ Code

```cpp
#include <bits/stdc++.h>

using namespace std;


int main() {
    
    // For fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXN = 1e8;

    int t;
    cin >> t;

    // 1-based indexing
    vector <pair <int, int>> N(t+1);
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
        now += 1.0 / i;
        // Could be duplicates, that's why using 'while' loop
        while (idx < (int)N.size() && N[idx].first == i) {
            ans[N[idx++].second] = now;
        }
    }

    for(int ts = 1; ts <= t; ++ts) {
        cout << fixed << setprecision(10) << "Case " << ts << ": " << ans[ts] << '\n';
    }

    return 0;
}
```
