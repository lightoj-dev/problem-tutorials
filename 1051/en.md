## Summary:
You will be given a string of containing capital letters and 0 or more '?' question marks. You can substitute '?' with vowel or consonant. A string is considered as `BAD` if it contains 3 vowels or 5 consonants in a row otherwise it is `GOOD`. It is `MIXED` if it can be made either good or bad by substituting '?' with consonant or vowel. You have to find wether a string is `GOOD` or `BAD`  or `MIXED`.

## Observations:

- If there is no '?' question mark in string and the string contains 3 vowels or 5 consonant in a row then it is `BAD` else it is `GOOD`.
- If the string contains '?' then it can be `GOOD` or `BAD` or `MIXED`.
- If the string contains 3 vowels or 5 consonants after substituting `one or more '?'` then it is `BAD`. If the string does not contain 3 vowels or 5 consonants in a row after substituting all '?' then it is `GOOD`. 
- If `all '?'` can be substituted in such a way that it can be `GOOD` and also can be `BAD` based on substituted letters in place of '?' then it is `MIXED`.	

You can make decision only at the positions containing '?'. You have two choices:
- Replace it by a vowel or,
- Replace it by a consonant.

## Solution:
Use `recursion` to solve this problem.
Iterate from first position to the last position of the string and in each position check if it contains 3 vowels or 5 consonants in a row from first position to current position.
If any position contains '?' then -
1. Replace it by vowel and check if it holds the condition to be `BAD`. If holds then it is bad and return `BAD`, else continue like this till the last position.
2. Replace it by consonant and check if it contains 3 vowels or 5 consonants from first position to this position. If contains then it is `BAD` and return `BAD`, else continue like this till the last position.

If you reach the last position of the string and does not hold the condition to be `BAD` then it is `GOOD` and return `GOOD`. If choice 1 and 2 both return `BAD` then the string is `BAD`.If both of them return `GOOD` then it is `GOOD`. If one of them return `GOOD` and another one of them return `BAD` then it is `MIXED`. If any one of them return `MIXED` then it is `MIXED`.

It is better to keep track of the number of vowels and consonants in a row from first position to current position instead of replacing '?' every time.  

### Algorithm:
S is the given string. vowel and cons are the number of vowels and consonants in a row.

Start from i=0 and continue till the last position of the string.

```
GOOD_OR_BAD(S, i, vowel, cons)

1.  if vowel == 3 or cons == 5: //base case
       return BAD
2.  if i>=s.size():	//base case
       return GOOD    

3.  if s[i] == '?':	//if s[i] contains '?' then make decision
        v = GOOD_OR_BAD(s,i+1,vowel+1,0) //replacing '?' with vowel will increase the vowels count in a row make consonant 0      
        c = GOOD_OR_BAD(s,i+1,0,cons+1) //replacing '?' with consonant will increase the consonants count in a row and make vowel 0

4.      if v!=c or v == MIXED or c == MIXED: //if one is good and one is bad or anyone of them is mixed
            return  MIXED
5.      else
            return v

6.  else if isVowel(s[i])) == true:	// if s[i] is vowel then increment number of vowel and make number of consonant 0
        return GOOD_OR_BAD(s,i+1,vowel+1,0)
7.  else:
      return GOOD_OR_BAD(s,i+1,0,cons+1) // if s[i] is consonant then increment number of consonant and make number of vowel 0
```
 This solution will cause `TLE`. To reduce the time complexity apply `dynamic programming`. Take a 3D array say `dp`. `dp[i][vowel][cons]` contains number of vowels and consonants in a row from position 0 to i for position i. Whenever it finds the optimal solution for position i it stores the result and the number of vowel and consonant for which it get optimal result in `dp[i][vowel][cons]`. Further, when an optimal solution is found in dp it returns the solution.
 
 ### Code(C++):
 ```cpp
#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

bool isVowel(char c){
    if(c=='A' or c=='E' or c=='I' or c=='O' or c=='U')
        return true;
    return false;
}
int goodBad(const string& s,int i,int vowel,int cons,vector<vvi>&dp)
{

    if(vowel == 3 or cons == 5)
        return 1;
    if(i>=s.size())
        return 0;
    if(dp[i][vowel][cons]!=-1)
        return dp[i][vowel][cons];
    if(s[i] == '?')
    {
        int v = goodBad(s,i+1,vowel+1,0,dp);
        int c = goodBad(s,i+1,0,cons+1,dp);
        if(v!=c or v == 2 or c == 2)
            return dp[i][vowel][cons] = 2;
        else
            return dp[i][vowel][cons] = v;
    }
    else if(isVowel(s[i]))
        return dp[i][vowel][cons] = goodBad(s,i+1,vowel+1,0,dp);
    else
        return dp[i][vowel][cons] = goodBad(s,i+1,0,cons+1,dp);

}
int main()
{
    vector<string>ans = {"GOOD","BAD","MIXED"};
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<vvi>dp(s.size(),vvi(s.size(),vi(s.size(),-1)));

        int res = goodBad(s,0,0,0,dp);
        cout<<"Case "<<cs++<<": "<<ans[res]<<endl;
    }  
    return 0;
}
 
```

