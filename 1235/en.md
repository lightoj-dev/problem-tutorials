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
Using this property , we can divide the n coins in two half. And have to push each coin two times . So size of each combination set will be 2^18 if we use bit manipulation
technique(we are mainly saving combination sum) . Then we can iterate through set-1 and check if any element in set-2 is there , that `set-1[i][+set-2[j] == K` , and to do this
we can do binary search or can save the value of set-2 in a map , and it will take `log n` time. But this solution will get TLE.<br/>
For improving our solution, let's see what is happening -<br/>
&nbsp; &nbsp; &nbsp; &nbsp; lets we have two coins `a`,`b`. We are pushing each element two times.<br/>
&nbsp; &nbsp; &nbsp; &nbsp; So , combination will be = `{a , a ,ab , ab , aab ...... ....... .. .. .. .. }`<br/>
**we are generating  same combination again and again !** So if we simply backtrack to generate combination instead of using bit manipulation , we can overcome this problem .

## **Solution Code(C++)**
```C++
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
#define visited 1
#define pi acos(-1)
#define inf 1<<30
#define lli long long int
#define sci(a) scanf("%d",&a)
#define sci2(a,b) sci(a);sci(b)
#define scli(a) scanf("%lld",&a)
#define scli2(a,b) scli(a);scli(b)
#define Case int t,cs=0;scanf("%d",&t);while(++cs<=t)
void sciar(int a[],int n){for(int i=0;i<n;i++)scanf("%d",&a[i]);}
 
lli sz1;
lli sz2;
lli ar1[20];
lli ar2[20];
vector<lli>combination1;
map<lli,bool>combination2;
void backtrackCombination(int pos,lli sum,int dir){
    if(dir==1 && pos>=sz1){
        combination1.push_back(sum);
        return;
    }
    else if(dir==2 && pos>=sz2){
        combination2[sum]=true;
        return;
    }
    lli num;
    if(dir==1) num=ar1[pos];
    else num=ar2[pos];
 
    backtrackCombination(pos+1,sum,dir);
    backtrackCombination(pos+1,sum+num,dir);
    backtrackCombination(pos+1,sum+2*num,dir);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    Case{
        lli n,k;scli2(n,k);
 
        if(n>1){
            sz1=n/2;
            sz2=n-sz1;
            for(lli i=0;i<sz1;i++)
                scli(ar1[i]);
 
            for(lli i=0;i<sz2;i++)
                scli(ar2[i]);
 
            ///make combination
            backtrackCombination(0,0,1);
            backtrackCombination(0,0,2);
 
            ///checking for the sum
            bool flg=false;
            for(lli i=0;i<combination1.size();i++){
                lli need=k-combination1[i];
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
            lli a;scli(a);
            if(a==k || 2*a==k)
                printf("Case %d: Yes\n",cs);
            else
                printf("Case %d: No\n",cs);
        }
    }
    //fclose(stdin);
    return 0;
}
```
