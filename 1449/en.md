# Problem Name: Redirect URL
## [LightOj-1449](https://lightoj.com/problem/redirect-url)
## Solution Approach:
 It is a simple basic implementation problem.<br>
 In this problem given a string which contain a URL link and you have been told redirect url  http:// to https://  protocol.
 For example : <br>
  url= "http://lightoj.com" <br>
so,  redirect url is "https://lightoj.com"<br>
You can simply done it in simple way .You can just check index 4 is 's' .<br>
 If index[4] is not 's' then insert 's' in index 4 and print it .Otherwise no change  print it.<br>

**Time Comlexity : O(1)** per test case.
# Cpp Code:
```cpp

#include <bits/stdc++.h>
using namespace std;
int main(){
      
      int test;
      cin>>test;
      for(int i=1; i<=test; i++){
            string x;
            cin>>x;
            if(x[4]!='s')x.insert(4,"s");
            cout<<"Case "<<i<<": "<<x<<endl;
            
      }    
}
```

Happy Coding!

Written by: [Md. Rasel Meya](https://www.linkedin.com/in/raselmeya/)