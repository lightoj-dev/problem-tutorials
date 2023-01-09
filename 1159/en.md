
# LOJ 1159
## Solution Approach:
This code is for finding the length of the longest common subsequence (LCS) of three strings. 
The LCS of three strings is the longest sequence of characters that appear in the same order in all three strings.

The function batman takes in three strings, X, Y, and Z, as well as their lengths, and returns the length of the LCS of the three strings. 
It does this by filling in a 3-dimensional array, L, using a bottom-up dynamic programming approach.

The base case is when either the length of X, Y, or Z is 0, in which case the LCS is 0. If the last characters of X, Y, and Z are the same,
then the LCS of the three strings is one more than the LCS of the three strings without the last characters. 
Otherwise, the LCS is the maximum of the LCS of the three strings with X, Y, or Z shortened by one character. 
# In short 
-if the string matches then it goes diagoanlly(add 1 and increase i,j,k index)
-if not then take max of neighbour elements



# C++
```

#include<bits/stdc++.h>
using namespace std;


int batman( string X, string Y, string Z, int m,
							int n, int o)
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

				else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1])
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;

				else
					dp[i][j][k] = max(max(dp[i-1][j][k],
										dp[i][j-1][k]),
									dp[i][j][k-1]);
			}
		}
	}

	//the last index should have the answer
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

	cout << "Case "<< idx<<": "<< batman(X, Y,
									Z, m, n, o)<<endl;;

	
}
}
```
