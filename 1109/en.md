# LOJ 1053 - False Ordering

In this problem, you will be given `T` test cases. Each test case contains an integer `N`, the value of which is **1000** at max. Your task is to print out the **N<sup>th</sup>** integer after arranging all the integers from **1** to **1000** following certain conditions.

**Conditions:** In the arrangement, the integer **x** will be placed before the integer **y** if: 
* `d(x) < d(y)`
* `x > y` when `d(x) = d(y)`

Note: `d(n)` denotes the number of divisors of the integer `n`

One approach to solve the problem is to pre-compute the arrangement and afterward, to print out the answer in `O(1)` time complexity. This can be achieved by:
1. Calculating the number of divisors of the integers using [modified sieve](https://codeforces.com/blog/entry/22229) technique
2. Computing the order of integers with the help of [custom comparison function](https://youtu.be/3pvZhwp0U9w) of C++

This is a very good problem to help you learn custom comparison in C++. However, some people might find it difficult to get an `Accepted` verdict. The reason could be one of the following:

1. Errors in calculating `d(n)`
2. Incorrect comparison conditions
3. Failing to provide proper output format
4. Missing new line on each line

If you are still stuck with this problem, check the code below:

### C++
-----
```cpp
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef pair<int, int> pii;
const int MX = 1e3;

pii d[MX];

bool order_cond (pii x, pii y) {
  if (x.s != y.s)
    return x.s < y.s;
  return x.f > y.f;
}

void pre_compute() {
  for (int i = 1; i <= MX; i++) {
    d[i - 1].f = i;
    for (int j = i; j <= MX; j += i) {
      d[j - 1].s++;
    }
  }
  sort(d, d + MX, order_cond);
}

int main() {
  int T, N;
  pre_compute();
  cin >> T;
  for(int i = 1; i <= T; i++) {
    cin >> N;
    cout << "Case " << i << ": " << d[N - 1].f << endl;
  }
  return 0;
}
```
