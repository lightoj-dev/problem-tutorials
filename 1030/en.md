# **LOJ 1030 - Discovering Gold**
## **Discussion:**
Given a `1XN` grid, each cell contains some gold. In the beginning, you stand at position 1. You have a perfect 6 sided dice, if after throwing you get a result `x`, then you will go `x` cell ahead and collect gold in it. </br>
You have to find the expected amount of gold you can collect.



## **Solution Idea**
- The probability  of getting 1, 2, 3, 4, 5 or 6 after throwing dice is `1/6`
- So, if you are now standing at position `i`, then the probability of going to `i+j` cell (where i<6) is 1/6.
    `(1/6 if i+6 <= N)`
- So, if we stand at position i, then expected amount of gold we can collect is: `(expected_value => Ex_v)` </br>
    `gold[i]+ ( 1/6*Ex_v(i+1) + 1/6*Ex_v(i+2) + 1/6*Ex_v(i+3) + 1/6*Ex_v(i+4) + 1/6*Ex_v(i+4) + 1/6*Ex_v(i+6) )` </br>
    It is true if `i+6 <= N`.
- If `i+6 > N` then we have to replace 6 with `N-i`, as we don't have 6 cases then.
- We have a recurrence relation, now based on this we can write a dp solution.
    



## **Solution Code(C++)**
```C++
#include <bits/stdc++.h>
using namespace std;

int n; 
int arr[200];
long double dp[200];

long double solve(int pos){
    if(pos == n) return arr[n];
    if(dp[pos] >= 0) return dp[pos];

    long double v = 0;
    for(int i=1; i<=6; i++){
        if(pos+i <= n){
            int dv = min(6, n - pos);
            v += (1.0/dv) * solve(pos+i);
        }
    }
    dp[pos] = arr[pos] + v;
    return dp[pos];
}
int main() {
    int t, cs = 1; cin>>t;
    while(cs <= t){
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        for(int i=0; i<=110; i++) dp[i] = -1;
        cout << fixed << setprecision(9);
        cout<<"Case "<<cs<<": "<<solve(1)<<endl;
        cs++;
    }
}
