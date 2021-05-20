# LightOj 1447 : Shadow Sum

## Summary 
*We are given T (T<= 25) test cases and an array of size N (1 <= N <= 20000). The elements of the array can be both positive and negative.*

*In this problem, if we find numbers with same magnitude we have to remove the previous one and insert the present one. That way, we have to build a new array and have to calculate its sum which is called "shadow sum".*

This is a basic implementation problem which involves two C++ structures, [set](https://www.geeksforgeeks.org/set-in-cpp-stl/) and [vector](https://www.geeksforgeeks.org/vector-in-cpp-stl/).

## Explanation

`5` and `-5` have the same magnitude. If array `a = {5, -5}` and array `b = {}` is empty:

if we iterate the array `a` then first we will insert `5` in array `b` as there is no number with that magnitude in array `b`.

Then we will move to the next index. Here we find `-5` which has the same magnitude with a previous element of array `b`, which is `5`.

So, to follow problem’s requirement we will delete `5` from array `b` and insert `-5` in `b`. 

In this case, the shadow sum = -5.

To check whether the number is present or not in the array before we may use STL "set".



## Solution

As we are removing the previous numbers with same magnitude so it's better to iterate the array from the last. We will use a operation of set – which is called `count()` to check whether that number with sign positive or negative is present or not.

If not then we will insert the number in set and move to next index. Thus we can find the array with no element of same magnitude and this way we will find the shadow sum and print it.

## C++ code
```C++
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n'

int main() {
    ll t; cin >> t;
    ll f = 0;
    while(t--) {
        f++;
        set<ll>ss;
        ll n; cin >> n;
        ll a[n + 2];

        for(ll i = 0; i < n; i++) cin >> a[i];
        for(ll i = n - 1; i >= 0; i--) {
        if(ss.count(a[i]) == 0 && ss.count((-a[i])) == 0)
            ss.insert(a[i]);
        }

        vector<ll>v(ss.begin(), ss.end());
        ll sum = 0;
        for(ll i = 0; i < v.size(); i++) {
            sum += v[i];
        }

        cout << "Case " << f << ": " << sum << '\n';
    }

    return 0;
}
```