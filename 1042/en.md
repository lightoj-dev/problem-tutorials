# LightOj 1042 - Secret Origins 
[Problem Statement](http://lightoj.com/volume_showproblem.php?problem=1042)  
### Summary
You'll be given a number as input. You have to find the next number that has the same number of `1`s in its binary representation.  
For example, if we're given `7` as input, its binary representation is `111`, and it has three `1`s. The next binary number with three `1`s is `1011`, which is `11` in decimal representation.  
  
### Hint
If you observe closely, you'll find out that the next binary number with the same number of `1`s is actually a permutation of the original binary number. In fact, it is the lexicographically next permutation of the original binary number.  
Now you can solve this problem using the `next_permutation()` function from C++ STL. You can check [this link](https://www.geeksforgeeks.org/stdnext_permutation-prev_permutation-c/) if you don't know about this function.  
All you need to do is just convert the decimal number into binary, then generate the next permutation of that number, then convert the new binary number to decimal again.

#### Bonus
This problem can also be solved using a bitwise technique called Gosper's Hack. To learn about this technique, please visit [this link](http://programmingforinsomniacs.blogspot.com/2018/03/gospers-hack-explained.html).  

### Code

#### C++
```cpp
#include <bits/stdc++.h>
using namespace std;

string dec_to_bin(int n) {
    string ret = "";
    for (int i = 31; i >= 0; i--) {
        int k = 1 << i;
        ret += (n & k)? '1' : '0';
    }
    return ret;
}

int bin_to_dec(string s) {
    int ret = 0;
    for (int i = 0; i < 32; i++) 
        ret = (2*ret) + s[i] - '0';
    return ret;
}

int main()
{
	int t, ca = 1;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        string bin = dec_to_bin(n);
        next_permutation(bin.begin(), bin.end());
        cout<<"Case "<<ca++<<": "<<bin_to_dec(bin)<<endl;
    }
    
    return 0;
}
```