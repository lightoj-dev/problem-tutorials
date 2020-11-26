# LOJ 1087 - Diablo
একটা উদাহরনের সাহায্যে বুঝা যাক। ধরি,n জন মানুষ এক লাইনে দাঁড়িয়ে আছে প্রত্যেকের একটি করে আইডি নাম্বার আছে।  
6 5 3 2 1 --->id  
1 2 3 4 5 --->there relative position  
আমাদেরকে ২ ধরনের কুয়েরী করা হবেঃ  

**ধরন ১:**  
a 20  
এটা মানে এখন যারা দাঁড়িয়ে আছে তাদের শেষে এই 20 আইডিযুক্ত লোক্টি দাঁড়াবে। এবং তাদের সবার রিলেটিভ অর্ডার হবে   
6 5 3 2 1 20 --->id  
1 2 3 4 5 6  --->there relative position  

**ধরন ২:**  
c 3  
৩ নাম্বারে থাকা লোকটিকে ডাকা হলো এবং সে তার পজিশন থেকে বের হয়ে যাবে।এই ধরনের কুয়েরীর জন্য আপনাকে লেফট সাইড থেকে অই পজিশনে থাকা লোকের আইডি নাম্বার প্রিন্ট করাতে হবে। এখানে এন্সার হবে ৩ কারন লেফট সাইড থেকে ৩ আইডি যুক্ত লোকটি ৩ নাম্বার রিলেটিভ পজিশনে ছিলো।  
এখন তাদের সবার রিলেটিভ অর্ডার হবেঃ  
6 5 2 1 20 --->id  
1 2 3 4 5  --->there relative position  


**অবসার্ভেশন ১:**  
আমাদের সর্বোমোট কুয়েরী সংখ্যা হইতে পারে ৫০০০০ টি। তার মানে আমাদের লিস্টে সর্বোমোট ১০০০০০ + ৫০০০০ জন নতুন করে পিছন দিকে এসে দাড়াতে পারবে।  

**অবসার্ভেশন ২:**  
প্রত্যেক মানুষের রিলেটিভ পজিশন হলো তার আগে যত জন মানুষ আছে + ১।  
**এক্সপ্লেইনেশনঃ**  
ধরি,যারা দাঁড়িয়ে আছে তাদের পজিশনের ভ্যালু ১ এবং যারা বের হয়ে যাচ্ছে তাদের পজিশনের ভ্যালু ০। তাহলে শুরুতে আমাদের এরে দেখতে যেমন দেখাবেঃ  
1 1 1 1 1  
1 2 3 4 5  

প্রথম কুয়েরীর পর যেমন দেখাবেঃ  
1 1 1 1 1 1  
1 2 3 4 5 6  

দ্বিতীয় কুয়েরীর পর যেমন দেখাবেঃ  
1 1 0 1 1 1  
1 2 3 4 5 6  

এখন যদি জিজ্ঞেস করা হয় যে, ৫ম পজিশনে থাকা লোকের রিলেটিভ পজিশন কত? উত্তর হবে ৪। কিভাবে উত্তর পেলাম?  
একটু খেয়াল করলে দেখা যায়,এই আর‍্যের প্রেফিক্স যেটি ৫ম পজিশনে এসে শেষ হয়েছে তার যোগফল ৪। এভাবেই আমরা রিলেটিভ পজিশন বের করতে পারি। তো আমাদের , এই রিলেটিভ পজিশন দেওয়া   থাকবে আমাদের বলতে হবে এই পজিশনে কে আছে। সেটাই অউটপুট হিসাবে প্রিন্ট করাতে হবে। তো আমরা যদি ২য় ধরনের কুয়েরীর এর সময় এই প্রেফিক্স এরে টা জানি,তাহলে আমাদের দেখতে হবে   সবচেয়ে বামের এই রিলেটিভ পজিশনে কে আছে।  

দ্বিতীয় কুয়েরীর পর প্রেফিক্স এরে টা যেমন দেখাবেঃ  
1 2 2 3 4 5  
1 2 3 4 5 6  

এই প্রেফিক্স এরে টা মেনটেইন করার জন্য আমরা [সেগমেন্ট ট্রী](https://cp-algorithms.com/data_structures/segment_tree.html) অথবা [বাইনারী ইন্ডেক্সট ট্রী](https://www.youtube.com/watch?v=CWDQJGaN1gY&t=447s) ব্যবহার করতে পারি। আর প্রেফিক্স সাম যেহেতু একটা মনোটনিক ফাংশন,আমরা এর উপর বাইনারী সার্চ চালিয়ে   সবচেয়ে বামের রিলেটিভ পজিশন বের করতে পারি এবং অই পজিশনে যে লোকটি দাঁড়িয়ে থাকবে তার আইডিই আমাদের প্রব্লেম এর এন্সার।  

**Note: use fast I/O :3**  
If you are still stuck with this problem, check the codes below:  

### C++
-----
```cpp  
#include<bits/stdc++.h>
using namespace std;
const int maxx=150005;
int BIT[maxx];

void update(int pos,int val){
    while(pos<=maxx-1){
        BIT[pos]+=val;
        pos+=(pos&-pos);
    }
}

int query(int pos){
    int res=0;
    while(pos>0){
        res+=BIT[pos];
        pos-=(pos&-pos);
    }
    return res;
}

void solve(){
    memset(BIT, 0, sizeof(BIT));
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int> vec(maxx);
    for(int i=1;i<=n;i++){
        scanf("%d",&vec[i]);
        update(i,1);
    }
    getchar();
    int en=n;
    for(int i=0;i<q;i++){
        char ch;
        ch=getchar();
        int x;
        if(ch=='c'){
            scanf("%d",&x); getchar();
            int lo=1,high=en;
            int ans=-1;
            while(lo<=high){
                int mid=(lo+(high-lo)/2);
                int xx=query(mid);
                if(xx>=x){
                    if(xx==x) ans=mid;
                    high=mid-1;
                }
                else lo=mid+1;
            }
            if(ans==-1) printf("none\n");
            else {
                printf("%d\n",vec[ans]);
                update(ans,-1); // Because the person who was standing at that ans position will come out and leave that position
                vec[ans]=-1;    // void. So,# of person will decrease by 1.
            }
        }
        else {
            scanf("%d",&x);getchar();
            vec[++en]=x;
            update(en,1);
        }
    }
}

signed main()
{
    int t;
    scanf("%d",&t);
    int cs=0;
    while(t--){
        printf("Case %d:\n",++cs);
        solve();
    }
    return 0;
}
```