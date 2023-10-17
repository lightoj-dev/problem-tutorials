## Dimik Decressing 

### What the problem wants 

Basically you will be show 1000 to 1;


### Solution 

The most basic way to solve this is as following 

- Take a variable count = 0;
- Start a loop from 1000 to 1 , 
- Print i'th number;
- Increase the count;
- Make a condition 

``` count % 5 == 0 ``` That means the remainder of count after dividing it by 5 is 0
- You can print a new line;
> Be careful about newline and extra space. If you are stuck with that problem see the code to know how to handle it

### CPP Code 

```cpp

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;
    for(int i = 1000; i >= 1; i--)
    {
        cout<<i<<" ";
        count++;
        if(count % 5 == 0)
            cout<<endl;
    }
}
```

### Efficiency 
