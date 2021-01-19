# LOJ 1020 - A Childhood Game

## Summary

In this problem, you have to find the winner of the game if both Alice and Bob play optimally.

The game is playing by alternating turns. In each turn a player can take exactly `1` or `2` marbles.

Both of them know the number of marbles initially. Now the game can be started by any one. But the winning condition depends on the player who starts it. If Alice starts first, then the player who takes the last marble looses the game. If Bob starts first, then the player who takes the last marble wins the game.

## Hint

Consider both of them different case. Start from 1 marbel and gradually increase the marbel. Try to find a pattern.

# Solution
## Approach

Lets consider '1' as first move and '2' as 2nd move. we will try to win first move(1) if possible.

If Alice start first,<br>

If `N = 1` 2 wins. who takes last loses<br>
If `N = 2` 1 wins. Alice takes 1 marbel and bob have to take last one.<br>
If `N = 3` 1 wins. Alice takes 2 marbel and bob have to take last one.<br>
If `N = 4` 2 wins. why ? if he takes 1 marbel opposite N(4-1) = 2 and if he takes 2 marbel opposite N(4-2) =2, So it is garanted 2 wins.
continue this process you will find pattern of 2 1 1 2 1 1 ... 

similar;y If Bob start first, you will find pattern of 1 1 2 1 1 2 ...

- Time Complexity: `O(1)` per test case.
- Memory Complexity: `O(1)` per test case.

## Code
### C++

```cpp

#include <bits/stdc++.h>
using namespace std ;

void _main_main()
{
    int n ;
    string s ;
    cin >> n >> s ;
    if(s == "Alice"){
        if (n%3 == 1) cout << "Bob\n" ;
        else cout << "Alice\n" ;
    }
    else {
        if (n%3 != 0) cout << "Bob\n" ;
        else cout << "Alice\n" ;
    }
}

int main ()
{
    int testCase = 1 ; cin >> testCase ;
    for (int i = 0; i < testCase; i++){
        cout << "Case " << i+1 << ": " ;
        _main_main() ;
    }
}




```

Happy Coding!

Written by: [Moontasir Mahmood](https://www.linkedin.com/in/munmud/)