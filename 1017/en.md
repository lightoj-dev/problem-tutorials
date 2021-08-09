# LOJ 1017 - Brush(III)

### Tags:
DP, Cartesian co-ordinate System, Binary Search

### Problem:
Given the co-ordinate of dust point. We have to find how many dust can we clean with w width brush after exactly K Moves.

### Helpful Resources:
 -  1.[Wiki: Cartesian Co-ordinate](https://en.wikipedia.org/wiki/Cartesian_coordinate_system)
 -  2.[Geekforgeeks: DP](https://www.geeksforgeeks.org/dynamic-programming/)
 -  3.[Youtube: BACS(DP)](https://www.youtube.com/watch?v=cbgdSX2pXcQ&t=2479s&ab_channel=BangladeshAdvancedComputingSociety-BACS)
 -  4.[Geekforgeeks : Binary Search](https://www.geeksforgeeks.org/binary-search/)

### Solution:
Basically, we need only y axis point.  
<img width="1200" alt="initial" src="https://github.com/ahrifatarafat/Lightoj-Tutorial/blob/main/LOJ_1017/LOJ_1017.JPG">
Here we see (0,0); (0,5); (20,5); (100,8); the four points then which way we solve we don’t need x axis points.
Then sort the y axis points and then we calculate in every moves how many dusts we can clean.
And also observe that if we start from non-overlapping points then we can clean most of them.
We first stored if we clean this dust then how many of them doesn’t overlapped before we can clean. And also how many of them we can take from front for clean. Then We can check in every moves how many dust we can clean.
We run a for loop from 0 to k for every moves and iterate over y axis point and calculate the maximum number of dust we can clean on index j of y axis after i moves and stored in dp[j].
After k moves we simply print the maximum of dp array.
Here we can see some execution

|   |   |   |   |   |
|---|---|---|---|---|
|   |   |   |   |   |
|   |   |   |   |   |
|   |   |   |   |   |

### Complexity:
 O(k*nlogn)

### Code:

### C++

 ```cpp
 #include<bits/stdc++.h>
 using namespace std;
 void solve()
 {
 	int n,w,k,x;
 	scanf("%d%d%d",&n,&w,&k);
  vector<int>a(n+1);
 	int dp[n+5];
 	vector<int>prev(n+1),mx(n+1, 0),poss(n+1);
 	memset(dp, 0, sizeof dp);
 	for(int i = 0; i < n; i++)scanf("%d%d" ,&x ,&a[i]);
 	a[n] = INT_MIN/2;
 	sort(a.begin(),a.end());
 	for(int i = 1; i <= n; i++){
         int p = upper_bound(a.begin(),a.end(),(a[i]+w)) - (a.begin());
         poss[i] = p-i;
         //cout << dp[0][i] << " ";
 	}
 	for(int i = 1; i <= n; i++){
         int p = lower_bound(a.begin(),a.end(), (a[i]-w)) -  a.begin();
         prev[i] = p-1;
 	}

 	for(int i = 0; i < k; i++){
         for(int j = 1; j <= n; ++j){
             dp[j] = poss[j] + (mx[prev[j]]);
         }
         for(int j = 1; j <= n; ++j){
             mx[j] = max(mx[j-1], dp[j]);
         }
 	}
 	cout << *max_element(dp+1, dp + n+1) << "\n";
 }

 int main()
 {
     #ifndef ONLINE_JUDGE
         freopen("inp.txt","r", stdin);
         freopen("out.txt","w", stdout);
     #endif // ONLINE_JUDGE
 	int t,cas = 0;
 	scanf("%d",&t);
 	while(t--){
 		printf("Case %d: ", ++cas);
 		solve();
 	}

 	return 0;
 }
 ```
