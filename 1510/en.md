## Aspect Ratio Solution

## Finding the Equation :
![1](https://github.com/lightoj-dev/problem-tutorials/assets/96460346/dfcf5824-ee6f-4eee-a517-88aa3ec5337e) 
![2](https://github.com/lightoj-dev/problem-tutorials/assets/96460346/ca88b89b-03a3-4c41-b919-40a19b5f522e)

### C++ Code
-----
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
  ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);      // Faster IO
  
  int t;
  cin >> t;
  for(int i=1;i<=t;++i) {
    cout << "Case " << i << ": ";
    double k;
    cin >> k;
    double d = ((k*k)-1)/(4-(k*k));                        // Equation we got
    double r = sqrtl(d);                                   // ""
    cout << fixed << setprecision(4) << r << '\n';         // The output should be rounded to 4 digits after the decimal point.
  } 
  
}
```

