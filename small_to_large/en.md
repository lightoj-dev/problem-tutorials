# Dimik - Small to Large

There will be three different numbers. They have to be printed from small to large sizes.

### Solution
* Case number will be according to the number of test case.
* Finding the middle number which is not min or max is the main task.

### C++
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int test_case;
    cin >> test_case;

    for (int i = 1; i <= test_case; i++){
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int a = min(min(n1, n2), n3);
        int b = max(max(n1, n2), n3);
        if (n1 != a && n1 != b)
        {
            cout << "Case " << i <<": " << a << " " << n1 << " " << b << endl;
        } else if (n2 != a && n2 != b){
            cout << "Case " << i <<": " << a << " " << n2 << " " << b << endl;
        } else if (n3 != a && n3 != b){
            cout << "Case " << i <<": " << a << " " << n3 << " " << b << endl;
        }
    }
    return 0;
}
```