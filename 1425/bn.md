# LOJ 1425- The Monkey and the Oiled Bamboo

ধরুন আপনি কাছে একটা মই আছে সেটা দিয়ে উপরে ওঠা লাগবে কিন্তু উঠার সময় কোন ধাপ বাদ দিতে পারবেন না,
ধাপে ধাপেই উঠতে হবে। এবং আপনাকে একটা এনার্জি দেওয়া আছে যার মান k। মানে আপনি এক লাফে সর্বোচ্চ k পরিমাণ 
উচ্চতায় উঠতে পারবেন। যদি আপনি এক লাফে k উচ্চতায় উঠেন, আপনার k এর মান এক কমে যাবে। 
এ থেকে বোঝা যায় যে আপনি k-1 উচ্চতায় লাফ দিতে পারবেন। আবার k-1 উচ্চতায় লাফ দিলে তারপর 
থেকে k-2 উচ্চতার বেশি লাফাতে পারবেন না। কিন্তু k এর কম উচ্চতায় লাফালে k একই থাকবে। 
আপনাকে ভূমি থেকে মইয়ের প্রতিটা ধাপের উচ্চতা দেওয়া হবে। আপনাকে এমন একটা k বের করতে হবে 
যা দিয়ে আপনি মইয়ের সবগুলো ধাপ পার করতে পারবেন এবং k এর মান যত সম্ভব ছোট হতে হবে।
আশা করি সমস্যাটা বোঝা গেছে 

আপনি যদি এখনও এই সমস্যায় আটকে থাকেন তবে নীচের কোডগুলি দেখুন:

### C++ 
-----
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