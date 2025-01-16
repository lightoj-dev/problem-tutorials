
## [LightOj-1093](https://lightoj.com/problem/ghajini)
## Problem Summary
Amir is playing a game called "Find Max Difference". But he can only remember numbers for a short period of time, that is `d` milliseconds.
The game involves:

- A sequence of integers appearing one at a time, for 1 millisecond each.
- The goal is to calculate the maximum difference between any two integers that Amir can remember(i.e., within the last `d` milliseconds).
- Input Constrains
	*  T <= 5 (Number of test case)
	*  2 <= n <=10^5 (Total number of integers the screen shows)
	*  1 <= d <= n (Amir memory duration)
	*  Sequence values: 0 <= a[i] <= 10^8





## Solution

- We will iterate the array. In each index we compare the minimum and maximum numbers from the last `d` integers. Amir remembers to maximize the difference and stores the max difference in a variable.
- A naive approach of iterating through the last `d` numbers for every index would be too slow((O(n * d)).
- We can efficiently find the minimum and maximum of the last `d` numbers using sparse table or segment tree. Then the complexity would be O(logn).

### C++ code using sparse table

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+1;
const int maxLog = 20;
int stMax[maxN][maxLog];
int stMin[maxN][maxLog];
int lg[maxN];
void init(int arr[],int n){
    for(int i=0;i<n;i++){
        stMax[i][0] = arr[i];
        stMin[i][0] = arr[i];
    }
    for(int j=1;j<maxLog;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            stMax[i][j] = max(stMax[i][j-1],stMax[i+(1<<(j-1))][j-1]);
            stMin[i][j] = min(stMin[i][j-1],stMin[i+(1<<(j-1))][j-1]);
        }
    }
}
int queryMax(int l,int r){
    if(l<0)l=0;
    int j = lg[r-l+1];
    return max(stMax[l][j],stMax[r-(1<<j)+1][j]);
}
int queryMin(int l,int r){
    if(l<0)l=0;
    int j = lg[r-l+1];
    return min(stMin[l][j],stMin[r-(1<<j)+1][j]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    lg[1] = 0;
    for(int i=2;i<maxN;i++){
        lg[i] = lg[i/2]+1;
    }
    int tcs;
    cin>>tcs;
    for(int tc=1;tc<=tcs;tc++){
        int n,d;
        cin>>n>>d;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        init(arr,n);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, queryMax(i-d+1,i)-queryMin(i-d+1,i));
        }
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }
}
```

## Resources
- [Sparse Table cp-algorithms](https://cp-algorithms.com/data_structures/sparse-table.html)
- [geeksforgeeks](https://www.geeksforgeeks.org/sparse-table/)

## Author
[Sudipta Singha](https://github.com/sudiptarathi2020)
