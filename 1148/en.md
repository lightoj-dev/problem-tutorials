# LOJ 1148 - Mad Counting

## Summary

In this problem, we have to find minimum possible people of the town by asking N people "How many people in this town other than yourself support the same team as you"

## Hint

Since we have to count the minimum possible people, It’s only possible when we can minimize the teams they are supported. For example,<br>

if `N = 1`; and poll result = `2`. The minimum possible people will be `3`. <br>
if `N = 2`; and poll result = `2, 2`.  the minimum possible people will be `3`. Since both of them said same answer, so we can say that both them in same team and another one. <br>
if `N = 3`; and poll result = `2, 2, 2`. Then the minimum possible people will be also `3`. Because all of them in same team. <br>
if `N = 4`; and poll result = `2, 2, 2, 2`. what will be the minimum possible people now? Here answer is `6`. Why? Because 1st person was predicted that the 2nd and 3rd person also supports same team. The 4th person supports another team and including another two person. So, 3 + 3 = 6.<br>

# Solution
## Approach

We have to count duplicate number for each value. After counting we have to find minimum number of teams. To do so , we know the maximum people for a team will be (value+1). So we divide the count with (value+1) and find the team number. If there is a reminder we add one extra team. Finally we multiply the team with the population(value+1) and add the result to final ans. <br>

See the example below: <br>
For N = 4 -> (2,2,2,2) <br>
Count (of 2) = 4 <br>
Team = (4/3) <br>
If there is a reminder of (4/3) team++ <br>
minimum possible people = (Team * 3)


- Time Complexity: `O(N)`  per test case.
- Memory Complexity: `O(N)`  per test case.

## Code
### C++

```cpp

#include <bits/stdc++.h>
using namespace std ;

void _main_main()
{
    map <int,int>mp ;
    long long int x, n, ans = 0 ;

    cin >>n ;
    for (int i = 0 ; i<n ; i++) {
        cin >> x ;
        mp[x]++ ;
    }
    for (auto i : mp){
        ans+= ( ( i.second / (i.first+1) )  + (  i.second % (i.first+1)  !=0 ?  1 : 0) ) * (i.first+1) ; 
    }
    cout << ans << "\n" ;
}



int main ()
{
    int testCase = 1 ;cin >> testCase ;
    for (int i = 0; i < testCase; i++){
        cout << "Case " << i+1 << ": " ;
        _main_main() ;
    }
        
}

```

Happy Coding!

Written by: [Moontasir Mahmood](https://www.linkedin.com/in/moontasir-mahmood-b5019b175/)
