# LightOJ 1097 - Lucky Number

## Summary
This problem requires you to find *n*th lucky number, where which numbers are called a lucky number in this context is explained in the problem statement. This problem requires some preprocessing and storing the lucky numbers, then printing the *n*th number for each test case.

This problems might be solved in many ways, including using a Segment Tree, but in this solution we will discuss how it is possible to solve this using [Policy Based Tree](https://codeforces.com/blog/entry/11080) from GNU G++ compiler. Please read about GNU PBDS and ordered set if you do not yet have a good understanding of Policy Based Data Structures.

Note that this approach can be used only if you have GNU G++ compiler or the required libraries for PBDS. If you have compilation error in your machine and you are sure that it is not some syntax error in code, most likely you are not using GNU G++ compiler or your compiler does not have the required libraries.

## Solution
Policy Based Tree from GNU PBDS can be considered as an STL set, but with some additional functionalities such as finding k'th order statistics (k'th smallest value) and the order of a key. In other words, you can find k'th element in the set and the number of elements less than a certain element efficiently, which is not possible with STL set.

If you have finally understood how to use it, then let's start discussing.

Before any test case, simulate the operation and generate an array that stores the first *10<sup>5</sup>* lucky numbers. In order to do that, you will need to check all the numbers till `mx = 1429431`. This simulation will not be much time consuming, as we are just iterating on the remaining indices of the multiples of a certain number. 

For each number `x` currently in the array, we will iterate over all the multiples `j` of `x` and find the `j`th numbers in the current array. After finding all of them, we will just delete them. Finding all the multiples requires *O(mx log<sub>2</sub>mx)* opearations, and deleting each of them requires *O(log<sub>2</sub> mx)* operation.

So, since we need to find all the `j`th elements and delete them efficiently, we will use PBDS for this array. Create an ordered set and store all the numbers from `1` to `mx`. Then just iterate one by one over the remaining elements `x`. For every multiple `j` of `x`, find the `j`th element, store it somewhere, do not delete it just yet. After you have found all the `j`th elements, delete all of them, and continue this process while it can be done. Note that if you delete some `j`th element before finding the next element whose index is also a multiple of `x`, the order of the elements after 'j' will change, so for the next value of 'j' you will not be able to find the one you need.

**Complexity:** *O(mx (log<sub>2</sub>mx)<sup>2</sup>)*

## C++ Code

```C++
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;

#define FIO() ios_base::sync_with_stdio(0);cin.tie(NULL);

template <class T>
using ordered_set = tree<T,null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mx = 1e5 + 3;
const int mxm = 1429431 + 20;

int ans[mx];

int main() {
    ordered_set <int> st;
    st.insert(0);

    for (int i = 1; i < mxm; i += 2) st.insert(i);

    ans[1] = 1;
    for (int i = 2; i < mx; i++) {
        if (st.size() <= i) break;
        int x = *(st.find_by_order(i));

        vector <int> v;
        for (int j = x; j < mxm; j += x) {
            if (j >= st.size()) break;
            v.push_back(*st.find_by_order(j));
        }

        for (int mul : v) st.erase(mul);

        ans[i] = x;
    }

    int tc; scanf("%d", &tc);
    int kase = 0;
    while (tc--) {
        printf("Case %d: ", ++kase);

        int n; scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
}

```