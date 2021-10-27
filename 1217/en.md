<h1>LightOJ 1217 Neighbor House (II)</h1>

<h3>Short description :</h3>
We are given <b><i>N</i></b> houses to soap. And houses are placed in circular position. <br>
<b>Condition to sell :</b> We can not select two Neighbor Houses to sell soap. <b>(1 and n are also Neighbor Houses)</b><br>
<b>Target : </b> Sell largest number of soap.<br><hr>
<h3>Solution Idea :</h3>
We can solve this problem using <b>Dynamic Programming</b> idea ( Here I use recursive DP).

Let's define <b>state</b> for recursion DP:</br>
<ol>
    <li>position (pos) ,</li>
    <li>is possible to take this position's value (taken),</li>
    <li>is first position's value taken or not (first).</li>
</ol>
<hr>
<b>Base case:</b> (pos>=n)<br>
<b>Normal case: (0 base index)</b><br> 
<ol>
    <li>If house position (pos)=0 then</li>
    <ol>
        <li>we can sell and go next house (pos+1) or</li>
        <li>we can go next house without selling.</li>
    </ol>
    <li>If taken=1 that means soap sold in previous house so we can not sell to current house so we must go next houese without selling</li>
    <li>If house position (pos)=n-1 it is last house so we have to check first house.</li>
    <ol>
        <li>If sold soap in first house we can not sell current house.</li>
        <li>Otherwise we can sell.</li>
    </ol>
</ol>
<br><br><hr>

If you still need some help for implementation. <br>

```c++
#include <bits/stdc++.h>
using namespace std;
int dp[1001][2][2];
int v[1001],n;
int fun(int pos, int taken, bool first){
    if(pos>=n)return 0;
    int &ret = dp[pos][taken][first];
    if(ret!=-1)return ret;
    ret=0;
    if(pos==0){
        ret=fun(pos+1,1,1)+v[pos];//sell in first house and move to next house
        ret=max(ret,fun(pos+1,0,0));//without selling move to next house
    }
    else if(taken or (pos==n-1 and first)){
        ret=fun(pos+1,0,first);//sold in neighbor house so without selling move to next house
    }
    else {
        ret = fun(pos+1,1,first)+v[pos];//sell in current house and move to next house
        ret = max(ret,fun(pos+1,0,first));//without selling move to next house
    }
    return ret;
}
int main(){
    int test,cs=1;
    cin>>test;
    while(test--){
        memset(dp,-1,sizeof dp);
        cin>>n;
        for(int i=0; i<n; i++)cin>>v[i];
        cout<<"Case "<<cs++<<": ";
        cout<<fun(0,0,0)<<endl;
    }
}
```