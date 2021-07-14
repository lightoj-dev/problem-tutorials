# Editorial for LOJ-1306: Solutions to an Equation

This is the classic question of finding the solutions for a linear Diophantine Equation. </br>
Reference: https://cp-algorithms.com/algebra/linear-diophantine-equation.html

```C++
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define fori(i,j,n) for(ll i=(ll)j;i<(ll)n;++i) 
ll gcd(ll a, ll b, ll& x, ll& y) {
    //Extended euclidean algorithm. Apart from giving the g=gcd(A,B), it gives an x and y which are solutions to the equation Ax+By=G. 
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){
 
    g=gcd(abs(a), abs(b), x0, y0);  //1. Apply extended Euclidean Algorithms
    if(c%g)                         //if it's not 0 then ax+by=c has no integral solution
        return false;
 
    x0 *=c/g;                       //2
    y0 *=c/g;                       //3
 
    if(a<0) x0=-x0;
    if(b<0) y0=-y0;
    return true;
}
void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}
 
ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))  //if there doesn't exist any solution of Ax+By=C then return 0
        return 0;
 
    //for the below part, I suggest reading the reference link
 
    a /= g;                                                                          
    b /= g;
 
    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;
 
    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;
 
    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    ll rx1 = x;
 
    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;
 
    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;
 
    if (lx2 > rx2)
        swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);
    if (lx > rx)
        return 0;
 
    return (rx - lx) / abs(b) + 1;
}
 
int main(){
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    fori(tst, 1, t+1){

        ll a, b, c, x1, x2, y1, y2;
        cin>>a>>b>>c>>x1>>x2>>y1>>y2;
     
        c=-c;                                                       //we are solving in Ax+By=C format but the i/p is in ax+by+c=0 format hence we reverse c's sign.
        cout<<"Case "<<tst<<": ";
        if(a==0 && b==0 && c==0) cout<<(x2-x1+1)*(y2-y1+1)<<'\n';   //this is the trivial case 0+0=0 and all numbers in the interval will satisfy the equation
     
        else if(a==0 && b==0) cout<<0<<'\n';                        //only a and b are 0 => 0=C
     
        else if(a==0){                                              //only a is 0, By=C
            if(c%b!=0 || y1>c/b || y2<c/b) cout<<0<<'\n';           //Ans is 0 when y doesn't exist ie. C doesn't divide B; or C does divide B but C/B doesn't fall in the given interval
            else cout<<(x2-x1+1)<<'\n';                             //if such a y exists in the given interval, then it can be paired with any x in the given interval     }
        }
        else if(b==0){                                              //Ax=C, same thing as above.
            if(c%a!=0 || x1>c/a || x2<c/a) cout<<0<<'\n';
            else cout<<(y2-y1+1)<<'\n';
        }
     
        else cout<<find_all_solutions(a, b, c, x1,x2,y1,y2)<<'\n'; //Above were the edge cases. Onto the real problem!
     }
    return 0;
}
```

Explanation for find_any_solution: 
From 1, we have a solution for Ax<sub>g</sub> + By<sub>g</sub> = g.

Multiply and divide by c/g to get:

c/g*(Ax<sub>g</sub>) + c/g*(By<sub>g</sub>) = c/g*(g)    <br/>
=> A(x<sub>g</sub> * c/g) + B(y<sub>g</sub> * c/g) = C  <br/>
Hence to obtain a solution for Ax+By=C, we multiply x0 and y0 by c/g in 2 and 3.

Afterwards we make the sign of x0 and y0 opposite to that of their coefficients. 


