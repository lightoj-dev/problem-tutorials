#LOJ-1247 Matrix Game

**Approch**

We have given a **N * M** Grid. A player can remove any number of stone from any row.
So a player can remove 1 to all stone from a row. We can assume all the stone in a row as a single pile of stone.
Then we will get N pile of stone.Now we can calculate xor sum of that pile and determine who is winner.

---
Lets assume now we have 4 pile { 9 , 7 , 11 , 5 }.

Lets convert them in Binary.
1001 = 9
0111 = 7
1011 = 11
0101 = 5

we can see every collum has even number of 1.When a player remove some stones from pile he will remove a 1 from it and the xorsum of the piles will be > 0. 
First player will remove 8 stones from the first pile then the binary state will look like
0001
0111
1011
0101
Then 2nd Player can remove 8 stones from 3rd pile and make the xor sum again 0.

As they play the game optimally so when a player gets xorsum>0 he will always win.

[More described](http://www.shafaetsplanet.com/?p=2608)


---

##Solution Code:
```C++
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define nl <<"\n"
typedef long long ll;

int main()
{
   int t;
   cin>>t;
   int tc=1;
   while(t--)
   {
       int n,m;
       cin>>n>>m;
       ll xorsum=0; //0 XOR A = A always.
       for(int i=0;i<n;i++)
       {
           ll sum=0;
           for(int j=0;j<m;j++)
           {
               int a;
               cin>>a;
               sum+=a;
           }
           xorsum^=sum; //Doing XORSUM
       }
       cout<<"Case "<<tc++<<": ";
       if(xorsum>0)
        cout<<"Alice" nl;
       else
        cout<<"Bob" nl;
   }
}
```
