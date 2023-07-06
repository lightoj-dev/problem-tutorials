# Dimik - Descending Number

In this problem,you will not be given any inputs.The only thing which you will have to do is to print all the numbers starting from 1 upto 1000 but in descending order.  

### Solution 
* Each number has to be seperated using the `space` character.
* Each line will consist of exactly 5 numbers not more nor less. 
  
### C++
```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cnt = 0;
    for (int i = 1000; i >= 1; i--)
    {
        cout << i << " ";
        cnt++;
        if (cnt == 5)
        {
            cout << endl;
            cnt = 0;
        }
    }
}
```
