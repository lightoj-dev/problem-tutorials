# Loj 1025 - The Specials Menu


_Given a string, find the number of ways to remove letters from the given string to make it palindrome._

---

#### Summary

For the `T` number of input set, where each input contain `S`, a word of characters, you have to find out how many palindrome you can make from this word by removing any number of characters.

#### Solution

_A palindrome is a word, number, phrase, or other sequence of characters which reads the same backward as forward, such as madam or racecar._

It's clear that palindrome check can be done in any word with `O(N)` time complexity using two pointers, one pointing to the beginning of the word  while another pointing to the end. In each step left pointer increase and right pointer decrease and it continues until there is any mismatch (not palindromic word) or both of the pointers pointing to the same position (odd length word) or they differ by one (even length word).


We can get one or more palindrome from any string by removing characters. 
For example, from **ANOKA** we can get, **A**, **AA**, **ANA**, **AOA**, **AKA**, **N**, **O**, **K**, **A**, total `9` palindromic strings. 

If we notice the example, the idea is pretty simple, by starting from beginning, for each character, we count the all possible lengths valid palindromic words. We can do this using recursion. For each position we call the recursive function to calculate all possible valid palindrome using the character at current position and also skipping it as well. 

So there can be two scenarios: 
- characters pointed by the pointers are same: `word[s] == word[e]`, in that case, the result will be sum of
  -  `1`, as the current index match, 
  - `calculate(s, e-1)` , all possible palindrome count using current index,
  - `calculate(s+1, e)` all possible palindrome count slipping current index.


- characters pointed by the pointers are unique: `word[s] != word[e]`, in that case, the result will be sum of
  - `calculate(s, e-1)` , all possible palindrome count using current index,
  - `calculate(s+1, e)`, all possible palindrome count slipping current index,
  - `calculate(s+1, e-1)`, skipping both of the characters.

_**Fact**:  as there will be lots of repetition, we can reduce that using the dynamic programming technique by string the data in a two dimensional dp table of  the input strings size._

#### Complexity Analysis: 

*Time Complexity*: for each index, we are tying all next possible indexes, so this gives us `O(N*N)` complexity, where `N`=`size of input`.

*Memory Complexity*: we are tying to store all in all possible length index of input size for each input length that gives us `O(N*N)` complexity, where `N`=`size of input`.


#### Code

### C++

```cpp

#include <bits/stdc++.h>

using namespace std;

string word;
long long dp[100][100];


long long calculate(int s, int e){
    // invalid case
	if(s > e) 
		return 0;

    // pointing at the same position
	if(s == e ) 
		return 1;

    // already calculated
	if(dp[s][e] != -1) 
		return dp[s][e];
    
    // when the charaters match
	if(word[s] == word[e]) 
		return dp[s][e] = 1 +  calculate(s+1, e) + calculate(s, e-1);
    // when the characters are unique
	else 
		return dp[s][e] = calculate(s+1, e) + calculate(s, e-1) - calculate(s+1, e-1);

}


int main(){
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; ++t){
        cout<<"Case "<<t<<": ";
        cin>>word;
        
        memset(dp, -1, sizeof dp);

        cout<<calculate(0,word.size()-1)<<endl;
    }
    return 0;
}
```