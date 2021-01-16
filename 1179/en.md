# LOJ 1437 - Beehives

## Summary

In this problem, you have to find the safe position of last person. We will start at 1 and kill next kth number from that position . <br>
For example, <br>
If n = 6 and k = 4, then the safe position is 5. The persons at positions 4, 2, 1, 3, 6 are killed in order, and person at position 5 survives.<br>
If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and person at position 4 survives.

## Hint

Try to think bottom to top recursive approach.

- Prerequisites : Recursion

# Solution
## Approach

The problem has following recursive structure.

`
    josephus(n) = (josephus(n - 1) + k-1) % n + 1
    josephus(1) = 1
`

After the first person (kth from beginning) is killed, n-1 persons are left. So we call josephus(n – 1) to get the position with n-1 persons. But the position returned by josephus(n – 1) will consider the position starting from k%n + 1. So, we must make adjustments to the position returned by josephus(n – 1).

- Time Complexity: `O(N)` per test case.
- Memory Complexity: `O(N)` per test case.

## Code
### C++

```cpp


#include <bits/stdc++.h>
using namespace std ;


long long num , k ;
long long josephus  ( long long n )
{
    if (n == 1) return 1 ;
    return ( josephus (n-1) + k -1 ) %n +1 ;
}

void _main_main()
{
    cin >> num >> k ;
    cout << josephus (num) << "\n" ;
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

Happy Coding! <br>

Written by: [Moontasir Mahmood](https://www.linkedin.com/in/moontasir-mahmood-b5019b175/)