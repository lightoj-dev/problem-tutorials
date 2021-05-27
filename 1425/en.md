# LOJ 1425- The Monkey and the Oiled Bamboo

Suppose you have a bamboo and you have to climb up using it.But here you can't skip any step when you climb up.
You must climb up step by step. Here you are also given an energy k.It means you climb up at most k steps.
When you jump and goto k steps then k will be decrease by one. So we can easily find that we can at most k-1 height jump.
Again if you jump k-1 heights, then you can jump at most k-2 heights.
Here you are given the height of every steps of the bamboo. Now you have to find k that which you cross all the steps using this k.
You have to find k as minimum as possible. 


If you are still stuck with this problem, check the codes below:

### C++ 

```c++
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll arr[100005], number;

bool check(ll mid)
{
    for(ll i = 0; i < number - 1; i++){
        ll dif = abs(arr[i] - arr[i + 1]);
        if(dif == mid) mid--;
        else if(dif < mid) continue;
        else return false;
    }
    return true;
}

ll binarySearch()
{
    ll low = 0, high = arr[number - 1];

    while (low <= high){

        ll mid = (low + high) / 2;
        if(check(mid)) high = mid - 1;
        else low = mid + 1;
    }
    return high;
}

int main() {
    ll tc, cs=1;
    scanf("%lld",&tc);
    while (tc--){

        scanf("%lld",&number);
        memset(arr, 0, sizeof(arr));
        for(ll i = 0; i < number; i++)
            scanf("%lld",&arr[i]);
        if(number == 1){
            cout << "Case " << cs++ << ": " << arr[0] << endl;
        } else {
            ll ans = binarySearch();
            cout << "Case " << cs++ << ": " << ans + 1 << endl;
        }   
    }
    return 0;
}
```
