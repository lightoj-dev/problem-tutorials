# **LOJ 1235 - Coin Change (IV)**

## **Discussion**
&nbsp; We may 1st think of generating all combinations and check that if the sum of any combination is equal to `K (sum == K)`. But, here `n<=18` and we can take each coin at most 2 times, 
so if we make combination using bit manipulation we will have `2^36` combinations, and it is too large. So this approach of generating all combination is not feasible. We will use
meet in the middle technique to solve it.
***
## **Solution Idea**
&nbsp;If set-1  `S1={a,b}` and set-2  `S2={c,d,e}`;<br/>
then all combination using set-1 and set-2 is- </br>
&nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp;           `{ a, b } X { c, d, e }  = { ac, ad, ac, bc, bd, be }`<br/>
Using this property , we can divide the n coins in two half. And have to consider each coin two times(reason is described below) . So size of each combination set will be `2^18` if we use bit manipulation technique(we are mainly saving combination sum) . Then we can iterate through set_1, which will take `O(n)` time and check if any element in set_2 is there , that `set_1[i]+set_2[j] == K` , and to do this we can do binary search or can save the value of set_2 in a map , and it will take (log n) time.So, the complexity after making combination is `O(nlogn)`. But this solution will get TLE.<br/>
For improving our solution, let's see what is happening -<br/>
&nbsp; &nbsp; &nbsp; &nbsp; Lets we have two coins `a`,`b`.<br/>
In the question, it is said that in the solution we can use the same coin at most 2 times. So a solution might consist of zero or one or two number of the coin `a`, but can’t
be anything else. Let’s see how binary counting is used to generate all combinations.<br/>
Consider this list `b b a a`  to generate the combinations using bit manipulation.<br/>
Here, List size = 4<br/>
So to get all combinations, we have to count from `1` to `2^4 - 1`(not considering empty set) in binary form and generate different combinations by considering the bit of the binary numbers.<br/>
#### Generating combinations from the list(bbaa) using bit manipulation: 
### &nbsp;&nbsp;&nbsp;&nbsp;  Binary number         &nbsp;&nbsp;&nbsp;&nbsp;  represented combination

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  0001          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  a<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  0010           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  a<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  0011           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  aa<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  0100           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  b<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  0101           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ba<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  0110           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ba<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ..............           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ..............<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  1011            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  baa<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ..............           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ..............<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  1111            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  bbaa<br/>

So, if we want to generate all combinations using bit manipulation we have to consider every coin two times otherwise we can’t generate combinations where the same coin appear
2 times. Maximum complexity for generating all combinations is `O(2^18)`.<br/>
And in this process, we are generating the same combination of the coin again and again (shown in the example above).<br/>
But if we backtrack to generate combinations, we can control that. We will choose every coin 0,1 or 2(generating 3 different state) times and then we will make a decision for the next coin. As we are going 
to 3 different state from every state and the maximum depth of this call is 9(max_list_size = 18/2), so to generate all combinations the complexity will be `O(3^9)`. In this way, the same combination will not be
generated and the run time of the solution will decrease. (it is not necessary to create the combination, we just need the sum) <br/>
Total complexity of our solution per test case is `O( 3^(n/2) + nlogn )`


## **Solution Code(C++)**
```C++
#include<bits/stdc++.h>
using namespace std;
 
long long int sz1;
long long int sz2;
long long int ar1[20];
long long int ar2[20];
vector<long long int>combination1;
map<long long int,bool>combination2;
void backtrackCombination(int pos,long long int sum,int dir){
    if(dir==1 && pos>=sz1){
        combination1.push_back(sum);
        return;
    }
    else if(dir==2 && pos>=sz2){
        combination2[sum]=true;
        return;
    }
    long long int num;
    if(dir==1) num=ar1[pos];
    else num=ar2[pos];
 
    backtrackCombination(pos+1,sum,dir);
    backtrackCombination(pos+1,sum+num,dir);
    backtrackCombination(pos+1,sum+2*num,dir);
}
int main(){
 	  int t,cs=1;
    cin>>t;
    while(cs<=t){
        long long int n,k;
        cin>>n>>k;
 
        if(n>1){
            sz1=n/2;
            sz2=n-sz1;
            for(int i=0;i<sz1;i++)
                cin>>ar1[i];
 
            for(int i=0;i<sz2;i++)
                cin>>ar2[i];
 
            ///make combination
            backtrackCombination(0,0,1);
            backtrackCombination(0,0,2);
 
            ///checking for the sum
            bool flg=false;
            for(int i=0;i<combination1.size();i++){
                long long int need=k-combination1[i];
                if(combination2[need]==true){
                    flg=true; break;
                }
            }
            if(flg==true)
                printf("Case %d: Yes\n",cs);
            else
                printf("Case %d: No\n",cs);
            combination1.clear();
            combination2.clear();
        }
        else{
            long long int a;
            cin>>a;
            if(a==k || 2*a==k)
                printf("Case %d: Yes\n",cs);
            else
                printf("Case %d: No\n",cs);
        }
        cs++;
    }
    return 0;
}
```
