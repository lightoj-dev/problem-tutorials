
# LOJ 1120 - Rectangle Union

**Problem:** The coordinates of the bottom left corner and the top right corner of the `n` `Axis Parallel` rectangles will be given. Calculate the area of the union area of the rectangles.

![](https://lh3.googleusercontent.com/MYHzwBqJGGxl5gw1OR5vZiYMcYVemWvesF9I6hvFXgUGZ6DQyG0_UyuVbf0knTKHPKBuHz923pK3TRWDyBggmzwuz_S8PqhlUJmLD2xGFhwR1OhWj0zpmFPUNDXGadeEvZSBsvw4S_t6VFmoWQ)

Example: The coordinates of the yellow rectangle in the figure above are `A(0, 2)` and `X(3, 6)`. The coordinates of the green rectangle are  `C(2, 1)` and `Y(5, 4)` and the coordinates of the blue rectangle are `W(1, 3)` and `M(6, 7)`. Then the combined boundary area (gray shaded part) of these three rectangles is 31.

**Solution:** First we start moving from left to right. Proceeding from point A, it can be seen that `ABGF` has formed a rectangle. The next rectangle is `BSIH`. If you go this way, `CDJI, DNLJ` and `OPML` rectangles are found. So, Area of ​​`(ABGF + BSIH + CDJI + DNLJ + OPML)` = Area of ​​the combined boundary of three rectangles in the example.

As it can be seen here, the main task is to find the sub-rectangles. A closer look reveals that the sub-rectangles can be calculated by finding out two consecutive x- coordinates and the lowest and highest y- coordinates between them. For example, for the rectangle `ABGF`, two consecutive x- coordinate points are A and W.  x-coordinates of B and W are the same. The lowest y-coordinate point between them is A (and B). And the point of the highest y- coordinate is F (and G ). 

Finding the F point's y- coordinate is not a difficult task. The point F is a point on the upper arm of the yellow rectangle. That is, the y- coordinates of the points X and F are the same. And the coordinates of the point X are obtained from the input. So, once the coordinates are found, it is possible to find the area of ​​the corresponding rectangle from the formula (x<sub>2</sub> – x<sub>1</sub>)×(y<sub>2</sub>– y<sub>1</sub>). One thing to note here is that since we are moving from left to right, if the right arm of a rectangle is crossed, nothing in that rectangle can be used in the next calculation. The calculation related to that rectangle ends there. One more thing to note is that although we used the x-coordinate of the W point of the blue rectangle to find the area of ​​the rectangle `ABGF`, we did not use any y- coordinates of this blue rectangle since `ABGF` rectangle is located to the left of the line `WH`. This problem can be solved in different ways including using segment tree, multiset, etc. **The name of this basic idea of traversing from one side to another side is line sweeping.**

If you have problems with implementation, you can read the following section.

We will discuss the coding approach using `Multiset` in **C++**. A structure will have the coordinates of the rectangle. Since we are moving from left to right, an index of the structure will have left x-coordinates x<sub>1</sub> and y-coordinates, y<sub>1</sub>, y<sub>2</sub> of a rectangle. Another index will have right x-coordinates x<sub>1</sub> and y-coordinates, y<sub>1</sub>, y<sub>2</sub>. There will be a variable named `state` in the structure to make it easier to understand whether the x- coordinates are left or right. If `state = 0` then it's left coordinate and if `state = 1` then the coordinate is the right's. Once the input is taken, the structure will be sorted ascendingly. Only x- coordinates will be compared when sorting. At the end of sorting, one by one the x- coordinates have to be taken from the structure and the y- coordinates have to be inserted in is `Multiset` to get the highest and lowest y- coordinates between two consecutive x- coordinates. When we pass the coordinates of the right side of a rectangle, that is, we get `state = 1` of an index of the structure, then its corresponding y-coordinates have to be erased from `Multiset`. The area of ​​the sub-rectangles can be easily obtained from two consecutive x- coordinates and the highest and lowest y- coordinates between them and the whole area can be obtained from them by adding their areas. <br> [Note: Be careful about calculating rectangles and the ordering of inserting/erasing y- coordinates in `Multiset`.]

### CODE:

### C++
-----
```c++
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
struct node {
    ll x, state, y1, y2;
} ara[60009];
 
bool cmp(const node &a, const node &b)
{
    return a.x < b.x;
}
 
int main()
{
    multiset <ll> ys;
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        ll indx = 1;
        for(ll i = 1; i <= n; i++) {
            ll x1, x2, y1, y2;
            scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
            ara[indx].x = x1, ara[indx].y1 = y1, ara[indx].y2 = y2, ara[indx].state = 0;
            indx++;
            ara[indx].x = x2, ara[indx].y1 = y1, ara[indx].y2 = y2, ara[indx].state = 1;
            indx++;
        }
 
        sort(ara + 1, ara + indx, cmp);
        ll ans = 0, lx;
 
        for(ll i = 1; i < indx; i++) {
            if(i != 1) {
                ll mny = *(ys.begin());
                ll mxy = *(--ys.end());
                ans += (ara[i].x - lx) * (mxy - mny);
            }
 
            if(ara[i].state == 0) {
                ys.insert(ara[i].y1);
                ys.insert(ara[i].y2);
            }
            else {
                ys.erase(ys.find(ara[i].y1) );
                ys.erase(ys.find(ara[i].y2) );
            }
            lx = ara[i].x;
        }
 
        printf("Case %lld: %lld\n", ++caseno, ans);
        ys.clear();
    }
 
    return 0;
}
```
This tutorial was first posted [here](https://shefin-cse16.github.io/post/loj-1120-editorial/).
