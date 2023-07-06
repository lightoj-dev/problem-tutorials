# LOJ 1044 - Palindrome Partitioning

## Summary
Given a string, we have to split it into its substrings so that all of them are palindromes, and the number of such substrings is minimized.

## Prerequisite
Basic Dynamic Programming

## Hint
Removing the first and the last character from a palindrome also results in a palindrome. For example: "a**bacab**a" is a palindrome and "b**aca**b" is also a palindrome so is "aca".

## Solution
Let's define:

isPalindrome[i][j] = whether the substring S[i...j] is a palindrome or not

dp[j] = minimum number of palindromic substrings that split the prefix S[0...j]

We compute the **isPalindrome** matrix beforehand using the above hint. However, in order to know whether the substring S[i..j] is a palindrome or not, we must know if the substring S[i+1.....j-1] is a palindrome or not. So we will go in increasing length of the substrings to determine whether the substring S[i...j] is a palindrome or not.

For a string S[0...j], if we take a palindromic suffix S[i..j] (0 <= i <= j), then the resulting string (excluding the suffix) has been reduced to a smaller subproblem to solve, S[0...i-1] (could be an empty string). And the answer would be dp[i-1] + 1 (for the palindromic suffix we have chosen). We don't know which suffix will yield the best outcome, so we try all such suffixes to find the optimum answer.

## Complexity
- Time Complexity: `O(T * (n^2))`.
- Memory Complexity: `O(n^2)`.

## Code

### C++

```cpp
#include <bits/stdc++.h>

using namespace std;


int main() {

    // for fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INF = 1e9;

    int t;
    cin >> t;

    for(int ts = 1; ts <= t; ++ts) {
        string str;
        cin >> str;

        int n = str.length();

        vector <vector <bool>> isPalindrome(n, vector <bool> (n, false));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= i; ++j) {
                isPalindrome[i][j] = true; // "" (empty) strings and a single letter are said to be palindromes.
            }
        }

        for(int len = 2; len <= n; ++len) {
            for(int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                isPalindrome[i][j] = isPalindrome[i+1][j-1] && (str[i] == str[j]);
            }
        }

        vector <int> dp(n, n);
        for(int j = 0; j < n; ++j) {
            for(int i = j; i >= 0; --i) {
                if (isPalindrome[i][j]) {
                    dp[j] = min(dp[j], (i > 0? dp[i-1]:0) + 1);
                }
            }
        }

        cout << "Case " << ts << ": " << dp[n-1] << '\n';
    }
    
    return 0;
}
```
