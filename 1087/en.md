# LOJ 1087 - Diablo

Starting with an example to understand the problem better.Suppose, we have n people standing linearly and everyone has assigned with an ID:
6 5 3 2 1 --->ID  
1 2 3 4 5 --->there relative position.  
We will have two queries:  

**For type 1:**  
a 20  
People with ID 20 will stand next to the last people standing already.The relative order of the list will be:  
6 5 3 2 1 20 --->ID  
1 2 3 4 5 6  --->there relative position.  
**For type 2:**   
c 3  
People who is standing in the 3rd position from the left will be called out and for this type of query ,you need to print the ID of that people.Here,the ans is 3 and   after this query the relative order of the list will be:  
6 5 2 1 20 --->ID  
1 2 3 4 5  --->there relative position.  

**Observation 1:**   
Number of q could be at most 50000 and initial number of people could be 100000. So for 1st type of query,we can observe that overall there could be at most 150000   people at a time.  
**Observation 2:**  
relative position of every people is the number of people standing right before him/her + 1.  

**Explanation:**  
Lets say,people standing in the array means his/her positional value is 1 and people called out means his/her positional value in that list is 0. In our  example,replacing with the value of the people ,initial array will look like,  
1 1 1 1 1   
1 2 3 4 5  

After query type 1,array will look like  
1 1 1 1 1 1  
1 2 3 4 5 6  
After query type 2,array will look like  
1 1 0 1 1 1  
1 2 3 4 5 6  


Now,if we are asked what is the relative position of the people standing 5th position?  
Ans will be 4. How can we calculate it?  
Well, the prefix ends in 5th position has the sum 4,that is how,we can find the relative position of any people standing anywhere.  
The prefix sum array will look like,  
1 2 2 3 4 5  
1 2 3 4 5 6  

The actual problem will give you the relative position of a people and you need to output the ID of that people who has the relative position the problem asked for   and of course the left most occurrence of that relative position is the ans.  

So,for prefix sum query and update we can use any range query data structure such as [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html),[Binary Indexed Tree](https://www.youtube.com/watch?v=CWDQJGaN1gY&t=447s).  
As,prefix sum array is a monotonic array,we can binary search for the leftmost occurrence of the relative position the problem will ask for.  

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