# LOJ 1089 - Points in Segments (II)

## Summary
The problem involves a set of one-dimensional segments and a set of points. The objective is to count, for each point, how many segments include that point within their range. 

Note: **AA** is a valid segment.

## Solution
First let's simplify the problem a bit. Suppose there is no such segment like: **AA** 

Let's think of each segment **AB** as of two points where **A** is the opening of the segment and **B** the ending of it. 

Consider the set of all opening and ending points of the segments sorted in increasing order. Iterating over the set from the beginning, only two case can arise. 

1. An opening point **p** indicating the segment (of that opening point **p**) has started running. By means of saying that any point that comes after it (or equal to that) and not after the ending of it will be contained in that segment. 

2. An ending point **p** indicating an ongoing segment has just been closed now and we can't take any point after that into the account of that segment (whose ending is **p**). 

We can sort our queries so that we can calculate answers for them in increasing order as we iterate over the set **S** while only maintaining a single counter.

That was the general approach. Now, solving the original problems is all about handling the exception case where we may have the same point for many openings and endings. See the code and comments for understading how to handle duplicate points.

## Complexity
- Time Complexity: O(T * (N * lg(N) + Q * lg(Q)).
- Memory Complexity: O(N + Q).

## Code

### C++

```cpp
#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;


int main() {
    
    // for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int ts = 1; ts <= t; ++ts) {
        int n, q;
        cin >> n >> q;

        vector <pii> point, query;
        vector <int> ans(q);
        for(int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            
            // 0 -> opening and 1 -> ending
            point.push_back({a, 0});
            point.push_back({b, 1});
        }
        sort(point.begin(), point.end());

        for(int i = 0; i < q; ++i) {
            int p;
            cin >> p;

            // saving each query with their corresponding index
            query.push_back({p, i});
        }
        sort(query.begin(), query.end());

        int cnt = 0, idx = 0, accumulator = 0, ending = 0;
        for(int i = 0; i < (int)point.size(); ++i) {
            if (point[i].second == 0) {
                accumulator++;
            }
            else {
                ending++; // segments that have been closed for the later points
            }
            if (i < (int)point.size() && point[i+1].first == point[i].first) { // accumulating cases with same opening or ending: (p, 0) or (p, 1)
                continue;
            }

            // case 1: query points strictly less than current point in consideration
            while (idx < q && query[idx].first < point[i].first) {
                ans[query[idx++].second] = cnt;
            }
            // case 2: query points equal to current point in consideration
            while (idx < q && query[idx].first == point[i].first) {
                ans[query[idx++].second] = cnt + accumulator;
            }
            cnt += accumulator-ending;
            accumulator = ending = 0;
        }

        // corner case: coming out of loop before the last point being considered
        while (idx < q && query[idx].first < point.back().first) {
            ans[query[idx++].second] = cnt;
        }
        while (idx < q && query[idx].first == point.back().first) {
            ans[query[idx++].second] = cnt + accumulator;
        }

        cout << "Case " << ts << ":\n";
        for(int i = 0; i < q; ++i) {
            cout << ans[i] << '\n';
        }
    }

    return 0;
}
```
