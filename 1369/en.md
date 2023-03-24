# LOJ 1369 - Answering Queries
---
First understand what the given code is doing here.
There will be two types of queries, one is calculating the sum and the other one is to change the value of an element of the given array `A[]`.

If you calculate the sum in the way the given code does, the complexity of the code will be O(t * q * n * n), which will not fit in `Time limit`.

So, we need to do the same thing what the given code does but in an efficient way. But what that way could be? Let's see!

Here we've to use contribution technique to solve this problem. Firstly, we will determine how much contribution an element of the array does to the `sum`.

For example, let's take an array of four elements ```a[4] = {1, 4, -2, 8};```

According to the given code, the `sum` will be the summation of `(1-4) + (1-(-2)) + (1-8)`, `(4-(-2)) + (4-8)` and `(-2-8)`

So, here first element is summed for 3 times and subtracted for 0 times, so the contribution of the `1` to the `sum` is `3 - 0 = 3`.
Again second element is summed for 2 times and subtracted for 1 times, so the contribution of `4` to the `sum` is `2 - 1 = 1`

In the same way, the contributions to the sum of the third element `-2` and fourth element `8` to the `sum` are `-1` and `-2` respectively.

So, in this way we will calculate the contribution of each element of the array to the `sum` and store it to an array named `contribution[n]`. How can we do that? Just observe the pattern: each element is summed for the exact same number of elements it has after it and that number will be `(n - index - 1)`. In the same way, each element is subtracted for the exact same number of elements it has before it and that number is the index of that element `index`. So we can calculate the contribution of each element in this way:
```
contribution[index] = (n - index - 1) - index;
```

Now we can calculate the `sum` by going through every element of the array and add `A[index] * contribution[index]` to the sum.

Even if the value of an element changes, the corresponding value in the `contribution` array of that element will still remain the same, because `contribution` array has nothing to do with elements' value rather it tells us how `sum` is calculated.

So, when the query will be to change the value of an element, we will just recalculate the `sum` in the following manner in constant time, no need to loop over the whole array.

```
sum -= arr[x] * contribution[x];
arr[x] = v;
sum += arr[x] * contribution[x];
```

The time complexity of this approach will be O(t * (n + q)). How?

As you need to loop over the whole array for each test case once, it will be O(n). For each query it will take O(1), so for q query, it will be O(q). So, for each test case time complexity will be O(n + q), and for t test cases total time complexity will be O(t * (n + q)). 

## Here is the c++ code
---
```cpp

/*
    Author: Arup Debnath
    Date: 24 March, 2023

    Happy Coding!!
*/

#include <bits/stdc++.h>
#define N ((int)1e5 + 5)

using namespace std;

int A[N];
int contribution[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int i = 1; i <= t; i++) {
        int n, q;
        cin>>n>>q;

        long long sum = 0;

        for(int j = 0; j < n; j++) {
            cin>>A[j];
            contribution[j] = (n-j-1) - j;
            sum += 1LL * A[j] * contribution[j]; // multiplying by 1LL is important because A[j] * contribution[j] can be greater than INT_MAX [2^31 - 1]
        }

        cout << "Case " << i << ":\n";
        while(q--) {
            int type;
            cin>>type;
            if(type == 0) {
                int idx, val;
                cin>>idx>>val;
                sum -= 1LL * A[idx] * contribution[idx];
                A[idx] = val;
                sum += 1LL * A[idx] * contribution[idx];
            } else {
                cout << sum << "\n";
            }
        }
    }
}
```