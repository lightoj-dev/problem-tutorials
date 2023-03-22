# LOJ 1183 - Computing Fast Average

## Summary
The problem requires implementing two types of queries on an array of integers (initially all values are 0):

1. Changing the value of elements in a range of indices with a specific value given. (**update query**)

2. Finding the average value of integers in a range of indices. (**get query**)

## Prerequisite
Segment tree with lazy propagation: 

https://cp-algorithms.com/data_structures/segment_tree.html#find-the-smallest-number-greater-or-equal-to-a-specified-number-acceleration-with-fractional-cascading 

(See the section titled **Range updates (Lazy Propagation)**)

## Solution
The solution is nothing but formulating it to the **range update-sum query**. The range update query is equivalent to the classic lazy update (setting a value to a range of indices) so is the range sum query. To form an irreducible fraction we divide both the nominator (range sum) and the denominator (total indices) by the gcd of them.

## Complexity
- Time Complexity: O(T * (N + Q * $log{_2}{N}$)).
- Memory Complexity: O(N).

## Code

### C++

```cpp
#include <bits/stdc++.h>
 
using namespace std;


struct SegmentTree {
    int n;
    vector <int> tree, lazy;

    SegmentTree(int n) : n(n) {
        tree.assign(n<<2, 0);
        lazy.assign(n<<2, -1);
    }

    void propagate(int now, int l, int r) {
        int left = now<<1;
        int right = left|1;

        int mid = (l+r)>>1;

        tree[left] = (mid-l+1) * lazy[now];
        tree[right] = (r-mid) * lazy[now];
        lazy[left] = lazy[right] = lazy[now];
        lazy[now] = -1;
    }

    void update(int now, int l, int r, const int i, const int j, const int val) {
        if (i > r || j < l) return ;
        if (i <= l && j >= r) {
            tree[now] = (r-l+1) * val;
            lazy[now] = val;
            return ;
        }

        int mid = (l+r)>>1;
        int left = now<<1;
        int right = left|1;

        if (lazy[now] != -1) propagate(now, l, r);

        update(left, l, mid, i, j, val);
        update(right, mid+1, r, i, j, val);

        tree[now] = tree[left] + tree[right];
    }

    int query(int now, int l, int r, const int i, const int j) {
        if (i > r || j < l) return 0;
        if (i <= l && j >= r) return tree[now];

        int mid = (l+r)>>1;
        int left = now<<1;
        int right = left|1;

        if (lazy[now] != -1) propagate(now, l, r);

        return query(left, l, mid, i, j) + query(right, mid+1, r, i, j);
    }
};

int main() {

    // for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int ts = 1; ts <= t; ++ts) {
        int n, q;
        cin >> n >> q;

        SegmentTree seg_tree(n);

        cout << "Case " << ts << ":\n";
        while (q--) {
            int type, i, j;
            cin >> type >> i >> j;

            // 1-indexing
            ++i;
            ++j;

            if (type == 1) {
                int v;
                cin >> v;
                seg_tree.update(1, 1, n, i, j, v);
            }
            else {
                int nominator = seg_tree.query(1, 1, n, i, j);
                int denominator = j-i+1;
                int gcd = __gcd(nominator, denominator);
                nominator /= gcd;
                denominator /= gcd;

                if (denominator == 1) cout << nominator << '\n';
                else cout << nominator << '/' << denominator << '\n';
            }
        }
    }

    return 0;
}  
```