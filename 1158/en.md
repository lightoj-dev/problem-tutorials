# LOJ-1158: Anagram Division
---
### Abridge
Given a string **s** and a positive integer **d**, you have to determine how many permutations of **s** are divisible by **d**.
Notice the constrains: $1<=|s|<=10$, $1<=d<=1001$.

### Approach
This problem can be solved by using Dynamic Programming
Let `dp[mask][remainer]` be the number of permutaions which include digits in **s** at positions identified by indexes of bit 1 in mask (from right most) and remainder when divided by **d**.
The transition:
dp[mask][new_remainder] = sum of all dp[old_mask][old_remainder] with old_mask is mask erased one bit 1.
You can look at the code for more detail.
If you are still wondering how to come up with these state and transition, feel ok because it's very good observation and you should look up for DP problems and try to solve them.

Because s might contain duplicated numbers, you should exclude those permutations as they've been counted repeatedly.

### Code
```
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
using ll = long long;

int f[11];
void solve_case(int nocase) {
	string s; cin >> s;
	int d; cin >> d;
	vector<int> digits;
	for(char c: s) digits.push_back(c-'0');
	int n = digits.size();
	vector<vector<int>> dp(1<<n, vector<int> (d, 0));
	// dp[mask][rem]: #permutations of length bit1(mask) and divide d remaining rem
	dp[0][0] = 1;
	for(int mask=1; mask<(1<<n); mask++) {
		for(int bi=0; bi<n; bi++) {
			if (mask&(1<<bi)) {
				for(int r=0; r<d; r++) {
					dp[mask][(10*r + digits[bi]) % d] += dp[mask^(1<<bi)][r];
				}
			}
		}
	}
	int ans = dp[(1<<n)-1][0];
	int cnt = 1;
	sort(digits.begin(), digits.end());
	for(int i=1; i<n; i++) {
		if (digits[i] != digits[i-1]) {
			ans /= f[cnt];
			cnt = 1;
			continue;
		}
		cnt++;
	}
	ans /= f[cnt];
	cout << "Case " << nocase << ": " << ans << endl;
}

int32_t main()
{
	IOS
	f[0] = 1;
	for(int i=1; i<=11; i++) f[i] = f[i-1] * i;
	int tc; cin >> tc;
	for(int c=1; c<=tc; c++) solve_case(c);

	return 0;
}

```


