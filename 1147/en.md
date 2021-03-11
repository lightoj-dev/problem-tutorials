# LightOJ 1147 - Tug of War

_Keywords: Dynamic-Programming_

There are `n` people with `w[i]` weights each; `n<=100`. You have to partition them into two sides so that there is at most 1 people extra in any group. You have to do this in such a way so that the summation of weights in each group is closer to another i.e. the absolute difference between the sum of weights is minimal. It's told that the sum of weight would be at most 100000. 

### Solution

The pretty obvious dp solution is, for each weight we make, we fix where we are currently, the number of people we will take more in the first group and try to reduce the taken weight to zero. If it's possible to make a desired weight by taking half or half+1 people (when `n` is odd) then this weight might be a solution.

To be specific, `dp[i][j][k]` will contain either `true` or `false` depending on whether we can make weight `k` taking exactly `j` people starting from people `[i, n)`. Now, for each `k` upto half of the weight we see if `dp[0][n/2][k]` is true. (Also `dp[0][n/2 + 1][k]` in case `n` is odd). If it's true then `k` is a possible weight for a group. We find such `k` upto half-weight of all people and the maximum is the summation of the first group.

The idea is pretty obvious. Only, it could get TLE or Memory Limit. About the memory limit, we only need to access `dp[i+1][][]` for `dp[i][][]`. So we can compress them (modulo 2). And to avoid TLE, note that not every `k` is needed to be traversed for a certain `i, j` if you sort the weights. You take only the possible weights for such combination and calculate them. This is a good optimization of runtime!

### C++ Code:

```cpp
const int N = 107;
const int W = 50000+7;
bool dp[2][N/2][W];	// dp[i][j][k] - possible or not from the i'th person taking j persons totalling w weight
int a[N], ca[N];	// sorted DESC, cumulative sum
int n;

int main() {
	int t, tc=0;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		for(int i=0; i<n; ++i) scanf("%d", a+i);
		
		sort(a, a+n);
		reverse(a, a+n);
		int sum = 0;
		ca[0] = 0;
		for(int i=0; i<n; ++i) sum += a[i], ca[i+1] = a[i]+ca[i];
		int half = sum / 2, nhalf = (n/2) + (n%2);

		memset(dp, false, sizeof dp);
		dp[n%2][0][0] = true;
		for(int i=n-1, ii=i&1; i>=0; --i, ii^=1) {
			int left = min(nhalf, n-i);
			for(int c=0; c<=left; ++c) {
				int wm = min(half, ca[i+c]-ca[i]);
				for(int w=0; w<=wm; ++w) {
					if(c < n-i) dp[ii][c][w] |= dp[ii^1][c][w];
					if(c and a[i] <= w) dp[ii][c][w] |= dp[ii^1][c-1][w-a[i]];
				}
			}
		}

		int res1 = 0, res2;
		for(int i=nhalf; abs(i+i-n)<=1; --i) {
			for(int w=half; w>=0; --w) {
				if(dp[0][i][w]) {
					res1 = max(res1, w);
					break;
				}
			}
		}
		res2 = sum - res1;
		printf("Case %d: %d %d\n", ++tc, res1, res2);
	}

	return 0;
}
```

### Further Improvement

Where the aforementioned solution is okay, there's another trick we can still do. Note that the number of people is at most 100. 
So the number of people in any group is at most 50. We use this number. What we do is, we keep a dp table for each weight. 
`dp[w]` will keep an upto 50 bits mask where `i`'th set bit means that we can make weight `w` using `i` people from the `n` people. 
For storing upto 50 bits, we can use `long long` data type.

What about the transitions? If we have calculated `dp[w]` for every `w` and for every index before `i`, we can write,
```
dp[w] = dp[w] | (dp[w - a[i]] << 1)
```
where `|` is the BITWISE-OR operator and `<<` is the BITWISE-LEFT-SHIFT operator.

### C++ Code:

```cpp
typedef long long ll;
const int N = 107;
const int W = 50000+7;
ll dp[W];	// dp[w] = i'th set bit means i people contribute to weight w
int a[N];

int main() {
	int t, tc=0;
	scanf("%d", &t);

	while(t--) {
		int n, sum = 0;
		scanf("%d", &n);
		for(int i=0; i<n; ++i) {
			scanf("%d", a+i);
			sum += a[i];
		}

		int half = sum/2;
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for(int i=0; i<n; ++i) {
			for(int w=half; w>=a[i]; --w) {
				dp[w] |= (dp[w-a[i]] << 1);
			}
		}

		int res1 = 0, res2 = sum, nh=n/2;
		for(int w=half; w>0 and !res1; --w) {
			if(dp[w] & (1LL << nh)) res1 = w;
			if(n&1 and (dp[w] & (1LL << (nh+1)))) res1 = w;
		}
		res2 = sum - res1;
		printf("Case %d: %d %d\n", ++tc, res1, res2);
	}

	return 0;
}
```

---

_[reborn++](https://lightoj.com/user/rebornplusplus)_ <br/>
_Aug 16 2018_
