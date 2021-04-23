# LOJ 1027 - A Dangerous Maze
*****Before reading this tutorial I would suggest you to read [this article](http://www.shafaetsplanet.com/?p=3060) for a better understanding of Mathematical Expectation*****

By the definition of Mathematical Expectation,<br>
If P(i) represents probability of choosing door i and T(i) represents time to get out of the maze if we choose door i,<br>
then for n number of doors,<br>
                Mathematical Expectation,<br> `E = P(1)*T(1) + P(2)*T(2) + P(3)*T(3) + ...... + P(n)*T(n)`<br>

Let's begin with analyzing the 3rd test case of the sample test case. 
The 3rd test case is -

3<br>
3 -6 -9

Here, we are given 3 doors. And we can only get out of the maze by the first door with a cost of 3 minutes. Where, the 2nd and 3rd door would return us to the same position costing 6 minutes and 9 minutes respectively.<br>
Let's assume the final expected time be E, what is our answer.<br>
So here,<br> `E = P(1)*T(1) + P(2)*T(2) + P(3)*T(3)`<br>

Each time we can randomly choose 1 door out of 3 doors and choosing one door is an independent event.<br>
So, probability of choosing any door would be 1/3.<br>
Thus, __P(i) = 1/3, for i = 1, 2, 3__<br>
Now, we need to calculate T(i) for i = 1, 2, 3<br>

If __i = 1__ i.e if we choose 1st door it would take us straight out of the maze. So __T(1) = 3__<br>
If __i = 2__ i.e if we choose 2nd door it would take 6 minutes but would return us to the same position!<br>
  So, sadly _**we would have to start the whole process onece again. As we assumped before that the final expected time is E, therefore we can safely say that for starting the whole process once again we will need E minutes more!**_<br>
  Thus time to get out of the maze if we choose 2nd gate<br>
  T(2) = Time to return to the same position + Expected time to get out of the maze for starting the process from beginning
  Therefore, __T(2) = 6 + E__<br>
Similiarly, if __i = 3, T(3) = 9 + E__<br>

So, finally,<br>
            `E = (1/3)*3 + (1/3)*(6 + E) + (1/3)*(9 + E)`<br>
            `E = (1/3)*(3 + 6 + 9) + (1/3)*(E + E)`<br>
            `(1/3)*(3*E - 2*E) = (1/3)*(3 + 6 + 9)`<br>
            `E*(3 - 2) = (3 + 6 + 9)` (Diving both sides by 1/3)<br>
       and, __E = (3 + 6 + 9)/(3 - 2) ......... (1)__<br>
       which ultimately yeilds, _**E = 18 / 1**_, which is our answer.<br>
      
If we look at equation (1), we can see,<br> __`3 + 6 + 9` is the sum of absoloute value of timetaken by each door.__<br> And, 3 is the number of doors and 2 is the number of reverse doors(doors that returns to the same postion). In other word, __`(3-2)` is the number of doors that can get us out of the maze.__

So, now we can have a genaralized solution for this problem,<br>
          ``` E = (sum of absolute value of the given times) / (number of gates that can take us out of the maze) ```
   
As, the output format is p/q, so both the the numbers divded by their GCD will be the ultimate solution.

### Special Case
If there are no gates that can take us out of the maze, we would never get out of the maze! So, the ans would be `inf`

### Complexity
As we are using a equation to solve the problem the time complexity would be simply of O(n)

### Solution in C++
```cpp
#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
#define endl '\n'
#define forn(i,n) for(ll i=0;i < ll (n); i++)
#define scan(n) scanf("%lld", &n);
#define print(n) printf("%lld", n);
#define pb(n) push_back(n)

void compute(ll a, ll b){
    ll x = __gcd(a,b);
    printf("%lld/%lld\n",a/x,b/x);
}

int main()
{
    ll t, no = 1;
    scan(t);
    while(t--){
        ll n;
        scan(n);
        ll a[n], sum = 0;
        forn(i,n) {scan(a[i]); sum+=abs(a[i]);}
        ll neg_sum = 0;
        forn(i,n){
            if(a[i]<0) neg_sum++;
        }
        printf("Case %lld: ",no++);
        if(neg_sum == n) printf("inf\n");
        else compute(sum,n-neg_sum);
    }
    return 0;
}
```
