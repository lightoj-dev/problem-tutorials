# Tag: Implementation , String 
# Difficulty : Easy 

## Hint : Consider the number as string 

## Solution 
* For each test case take input as string (unless you are working with python)
* Check the last character 
* convert it to integere 
* if its even 
  * print 'even'
* if its odd 
  * print 'odd'
### for python user 

* For python just take input 
* check if its divisible by 2 or not 
* if yes 
  * print 'even'
* else
  * print 'odd'
  
  ## C++ Implementation 
  ```
  #include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s; // taking number as string 
        int t=s[s.size()-1]-'0'; // making last character as integer
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
  
  ## Python implementation 
  ```
  t=eval(input())
for i in range(t):
    a=eval(input())
    if(a%2==0):  // checking if the number is divisible by 2 or not 
        print("even")
    else:
        print("odd")
  ```
