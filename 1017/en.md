# LOJ 1017 - Brush(III)
___
**Tags :**
DP, Cartesian co-ordinate System, Binary Search

#### What the problem wants:
Given the co-ordinate of dust point. We have to find the highest number of  dust we can clean with `w` width brush after exactly `K` Moves.


### Solution:


#### Algorithm of the Solution:
	1. Sort all the values of y axis.
	2. Check how many dust particles we can cover if we start the brush from given point.
	3. Find the sum of covered dust for each step. Starting from given point.
	4. The maximum covered dust at the last step is the required answer.

#### Explanation of the steps

We will sort all the values of y to check how many particles we can cover in one stroke. Since the stroke is done along the x-axis in each stroke we can sweep all the dusts in the range of `starting point + width of the brush` or `starting point - width of the brush`.
<img width="1200" alt="initial" src="https://github.com/ahrifatarafat/Lightoj-Tutorial/blob/main/LOJ_1017/LOJ_1017.JPG">
Lets take an example if there are dust particles at  (1,1) , (2,2) , (3,3) , (4,4) .

We can use binary search to find the total number of dust particles within a given range efficiently.

since the way to sweep the highest number of dust in limited (k) number of strokes is to find the non-overlapping (k) strokes that sweeps the most dust , we can do so by checking how much dust will be swept if the stroke is made either starting or ending at each individual dust particle.

The reason we consider non-overlapping strokes is because its the most efficient method.

---
#### Example  Test Case :
```
1
10 16 3
1 9
8 19
3 21
2 29
5 44
7 57
7 72
1 83
1 94
3 97
```

Y axis points : 9, 19, 21,29,44,57,72,83,94,97

W = 16 </br>
K = 31

|array (index)|  0 |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  | 9  |
|-------------|----|-----|-----|-----|-----|-----|-----|-----|-----|----|
|array (value)|  9 |  19 | 21  |  29 |  44 | 57  | 72  | 83  | 94  | 97 |
|poss(a[i]+w) | 25 | 35  |  37 | 45  | 60  | 73  |  88 |  99 | 110 |113 |
|prev (a[i]-w)| -8 | 2   |  4  | 12  | 27  | 40  |  55 |  66 | 77  | 80 |
|1st Move     |  3 | 3   |  2  |  2  |	2  | 2   |  2  | 3   |	2  | 1  |
|2nd Move     |  3 |  3  |   2 |  5  |	5  |  5  |  5  | 6   |	5  |  4 |
|3rd Move     |	3  |  3  |   2 |  5  |	5  |  7  | 7   | 8   |	7  |  6 |

In the table `poss(a[i]+w)` is the range in which all dust particles are covered if we start the stroke from that particular point and `prev (a[i]-w)` is the range for strokes that end at that point.

Then we just calculate the maximum porssible dust we can clean after each stroke.

**Time Complexity :**
 `O(k*nlogn)`

#### Helpful Resources:
 -  1.[Wiki: Cartesian Co-ordinate](https://en.wikipedia.org/wiki/Cartesian_coordinate_system)
 -  2.[Geekforgeeks: DP](https://www.geeksforgeeks.org/dynamic-programming/)
 -  3.[Youtube: BACS(DP)](https://www.youtube.com/watch?v=cbgdSX2pXcQ&t=2479s&ab_channel=BangladeshAdvancedComputingSociety-BACS)
 -  4.[Geekforgeeks : Binary Search](https://www.geeksforgeeks.org/binary-search/)
___


### Solution Code:

### C++

 ```cpp
 #include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,w,k,x;
    scanf("%d %d %d",&n,&w,&k);
    vector<int> a(n+1);
    int dp[n+5];
    vector<int> prev(n+1), mx(n+1, 0), poss(n+1);
    memset(dp, 0, sizeof dp);

    for(int i = 0; i < n; i++)
        scanf("%d %d",&x,&a[i]);

    a[n] = INT_MIN/2;
    //sorting all y axis with a inf negetive number
    sort(a.begin(),a.end());
    // find the total number of dust particles within a given range in front
    for(int i = 1; i <= n; i++){
        int p = upper_bound(a.begin(),a.end(),(a[i]+w)) - (a.begin());
        poss[i] = p-i;
    }
    //find the total number of dust particles within a given range in back
    for(int i = 1; i <= n; i++){
        int p = lower_bound(a.begin(),a.end(), (a[i]-w)) -  a.begin();
        prev[i] = p-1;
    }

    for(int i = 0; i < k; i++){
        // find the maximum we can clean after (i+1) move if we take the point j
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
    int t,cas = 0;
    scanf("%d",&t);
    while(t--){
        printf("Case %d: ", ++cas);
        solve();
    }

    return 0;
}

 ```
