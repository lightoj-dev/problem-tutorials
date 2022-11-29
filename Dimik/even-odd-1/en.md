# Tag: Implementation 
# Difficulty: Easy 

## Hint: You just need to handle last bit 

### Solution 
* for each test case take the number as a string 
* Check the last character of the string 
* make it integer 
* If its divisible by 2
  * its a even number so print 'even'
* if its not divisible by 2 
  * its a odd number so print 'odd'


**C++ Implementation**

```
#include<bits/stdc++.h>  // includes everything 
using namespace std; 
int main()
{
    int t;
    cin>>t;
    while(t--)   // taking input unless test case ends
    {
        string s;
        cin>>s;
        int t=s[s.size()-1]-'0';  // last digit of the string 
        if(t%2==0)
        {
            cout<<"even"<<endl;
        }
        else
        {
            cout<<"odd"<<endl;
        }
    }
}

```
