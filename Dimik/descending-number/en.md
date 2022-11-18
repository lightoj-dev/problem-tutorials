# Tag : Implementation 
# Difficulty : Beginner 

## Hint: Loop can start from 1000 . The last digit of a line should not carry any extra space 

### Solution :
* Start a loop 
* Intial value should be 1000 
* decreament by 1 in each iteration 
* If the iterator's value is divisible by 5 
  * print a newline
  * Otherwise print a space 
* Loop should end when it reaches 1 

### C++ implementation 
```
#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=1000;i>=1;i--)  // starting the loop from 1000 and decreament it by 1 
    {
         if(i%5==0&& i<1000) // new line condition 
             cout<<endl;
         else if(i<1000)
             cout<<" ";
        cout<<i;
    }
}
```
