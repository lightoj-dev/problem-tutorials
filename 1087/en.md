# [http://lightoj.com/volume_showproblem.php?problem=1087](http://lightoj.com/volume_showproblem.php?problem=1087 "1087 - Diablo") #


Starting with an example to understand the problem better.

Suppose, we have n people standing linearly and everyone has assigned with an id:
6 5 3 2 1 --->id
1 2 3 4 5 --->there relative position
we will have two queries:

for type 1:
a 20
people with id 20 will stand next to the last people standing already.
the relative order of the list will be:
6 5 3 2 1 20 --->id
1 2 3 4 5 6  --->there relative position

for type 2:
c 3
people who is standing in the 3rd position from the left will be called out and for this type of query ,you need to print the id of that people.
here,the ans is 3 and the relative order of the list will be:
6 5 2 1 20 --->id
1 2 3 4 5  --->there relative position

observation 1:
number of q could be at most 50000 and initial number of people could be 100000. So for 1st type of query,we can observe that overall there could be at most 150000 people 
at a time.
observation 2:
relative position of every people is the number of people standing right before him/her + 1.

Explanation: 
lets say,people standing in the array means his/her positional value is 1 and people called out means his/her positional value in that list is 0
in our example,replacing with the value of the people ,initial array will look like,
1 1 1 1 1 
1 2 3 4 5

after query type 1,array will look like

1 1 1 1 1 1
1 2 3 4 5 6

after query type 2,array will look like
1 1 0 1 1 1
1 2 3 4 5 6


now,if we are asked what is the relative position of the people standing 5th position?
ans will be 4. how can we calculate it?
well, the prefix ends in 5th position has the sum 4,that is how,we can find the relative position of any people standing anywhere.
the prefix sum array will look like,
1 2 2 3 4 5
1 2 3 4 5 6

the actual problem will give you the relative position of a people and you need to output the id of that people who has the relative position the problem
asked for and of course the left most occurrences of that relative position is the ans.

So,for prefix sum query and update we can use any range query data structure such as segment tree,Binary Indexed tree.
As,prefix sum array is a monotonic array,we can binary search for the leftmost occurrence of the relative position the problem will ask for. 

**Note: use fast I/O :3**

----------


**Code: C++:**
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
    rep1(i,1,n){
        scanf("%d",&vec[i]);
        update(i,1);
    }
    getchar();
	int en=n;

    rep(i,q){

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
                update(ans,-1);
                vec[ans]=-1;
            }
        }
        else {
            scanf("%d",&x);getchar();
            vec[++en]=x;

            update(en,1);
        }
    }

}