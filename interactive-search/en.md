 #  Interactive Search

 ## Problem
 This is an easy interactive problem . You will be a value `n` and you have to find the secret number which is within  `1` to `n` in `30` tries . You will be given a response `high` or `low` or `correct` . If you guess the number in `30` tries you will get `AC` otherwise `WA` .

 ## Solution

 The maximum value of `n` is `1e9` so we can't use linear search .

 As the number of tries is `30` we can use binary search to find the number because to find a number within a range of `1` to `1e9` it will take binary search maximum `log2(1e9)` which is okay for our problem.


 So we will use binary search to find the number . 
 ```
 1. We will take the input of `n` and set the `low` as `1` and `high` as `n`. 
 2. Then we will find the mid value and print it as guess .
 3. Then we will take the response as input . 
 5. If the response is `high` then we will set `high` as `mid - 1` .
 6. If the response is `low` then we will set `low` as `mid + 1` .
 7. If the response is `correct` then we will return . 
 8. If the count is greater than `30` then we will print `too many tries` and return .
```

You can learn more about binary search from 
1. [geeksforgeeks](https://www.geeksforgeeks.org/binary-search/)
2. [cp-algorithms](https://cp-algorithms.com/num_methods/binary_search.html)

```
 Time Complexity : O(log(n))
 Space Complexity : O(1)
```


 
 
 ## CPP
```cpp

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int low = 1, high = 100000;
    // Taking the value of n as input and setting it as high as it will be the maximum value
    cin >> high;


    // To keep track of the number of tries
    int count = 0;

    // Binary search
    while (low <= high)
    {
        // Finding the mid value
        int mid = (low + high) >> 1;
        // Printing the guess
        cout << "guess " << mid << endl;


        // Taking the response as input
        string response;
        cin >> response;

        // Checking the response
        if (response == "correct")
            return 0;
        else if (response == "high")
            high = mid - 1;
        else if (response == "low")
            low = mid + 1;

        // Increasing the count
        count++;

        // If the count is greater than 30 then printing too many tries and returning
        if (count >= 30)
        {
            cout << "too many tries" << endl;
            return 0;
        }
    }

    return 0;
}
```
