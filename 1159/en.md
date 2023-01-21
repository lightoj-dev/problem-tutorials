
# [LOJ 1159 Batman](https://lightoj.com/problem/batman)

## Solution Approach:
In this problem given 3 string and need to find the length of the longest common subsequence 
[LCS](https://www.programiz.com/dsa/longest-common-subsequence) of these three strings.



Let's define LCS[i][j][k] to be the LCS of the three sub-strings X[1..i], Y[1..j], Z[1..k].


To compute the value of LCS[i][j][k], we consider three possibilities:
- You can start by checking base case whether the length of any string is 0, in which case the LCS is 0.
- if last characters of each string match, length of the common subsequence would be 1 plus 
  the length of the common subsequence till the i-1,j-1 and k-1 indexes
- Otherwise, we can drop the last character of any one of the three strings and take the maximum value i.e. LCS[i][j][k] = max(LCS[i-1][j][k], LCS[i][j-1][k], LCS[i][j][k-1]).



The final LCS value is stored in LCS[len[X]][len[Y]][len(Z)], which is the LCS of the three input strings.

This problem is similar to [this problem](https://leetcode.com/problems/longest-common-subsequence/description/), you can check that also.


# C++
```
#include<bits/stdc++.h>
using namespace std;


int LCS( string X, string Y, string Z, int m, int n, int o)
{
	int dp[m+1][n+1][o+1];

//Going with bottom up aproach
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			for (int k=0; k<=o; k++)
			{
				if (i == 0 || j == 0||k==0)
					dp[i][j][k] = 0;

				else if (X[i-1]==Y[j-1] && X[i-1]==Z[k-1])
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;

				else
					dp[i][j][k] =max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
			}
		}
	}

	
	return dp[m][n][o];
}


int main()
{

    int len;
    cin>>len;
    for(int idx=1;idx<=len;idx++){
       string X,Y,Z;
       cin>>X>>Y>>Z;
       int m = X.length();
       int n = Y.length();
       int o = Z.length();
       cout << "Case "<< idx<<": "<< LCS(X, Y,Z, m, n, o)<<endl;

	

	   

	
}
}
```
