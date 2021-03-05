# LOJ 1239 - Convex Fence

In this problem, you will be given `T` testcases. The first line of each test case contains an integer two integers `n` and `d` where `n` denotes the number of points and d is the minimum distance told to maintain from each and every of these coordinating points. The next line consists of `2*k` integers where the even indexed integers denote the position of gray pieces whereas the odd indexed integers denote the white pieces on the board.Now Alice, the first player gets to move the grey pieces to the right and the second player, Bob gets to move the white pieces of the board to the left.Now in each move either player can move from 0 to abs(Bob's-Alice's-1) pieces.
The next n lines denotes the coordinates of the points.Now, in the problems statement it was told to draw fence around the convex hull we build,such that each of the points maintain a minimum distance of d.


### Approach:
In order to solve this problem, there are a few prerequisites that need to be fulfilled which are: you need to have a basic understanding of how to generate convex hull from given coordinating points and how to find the distance between two coordinating points using Euclidean Distance Formula . The tutorials are given below in the "Resources" section.

So having a clear concept of the topic mentioned above, we can solve this problem.
At first we have to construct the hull by merging the upper and lower hull using the basic algorithm.Now there are two cases.
1) If the hull consists of a single point: If it is true then we are to draw a circle around that point maintaining a distance of d from that point because that would ensure the minimum perimeter of the fence.Having a distance greater than d will only maximize the perimeter which we don't want to solve this problem.
2) If the hull consists of points greater than one,then it might be impossible to draw a circle around all points so that the points have atleast distance of d.In that case,we need to draw a oval around it so that we can ensure a distance of d from all the points.

Now assuming you have built the hull,now you might be wondering what if one point of the hull is very close to the centre while the other point is far off from the centre.How am I supposed to build the fence around such a hull?
The answer to that is you don't have to manually calculate from each point to check minimum distance of d is ensured.What you need to do is calculate the perimeter of the convex hull.Now if you have a single point the hull,the perimeter is zero.
But if the hull consists of more than one point you are to find the perimeter of the hull by summing up all the distance of two consective coordinating points using Euclidean Distance Formula.Now in hull we know that the last point is connected with the first point in that case you can use modulus operator to find the distance in that case.
Now assuming you have found the perimeter of the convex hull,if the hull consists of a single point we can draw a circle around that point of radius d considering that point as the centre.Now that circle is the fence maintaing a distance of d from the point.
As the perimeter is zero for a single point so perimeter of the fence is equal to the perimeter of the circle which equals to 2*pi*d
Now if the hull consists of more than one point,we need to imagine the entire hull as a single point that is as a centre of a circle and we need to draw a circle around that maintaing a radius of d.
Now in reality we can't draw a proper circle but mostly an oval is possible.But for better understanding imagine the hull itself is the centre and draw a circle around it having a radius of d.
So ,perimeter of fence=perimeter of convex hull+perimeter of the circle=perimeter of convex hull+ 2*pi*d
### Resources:
Here are some resources of **How Convex Hull is generated** so that you can have a deeper understanding on these topics and learn to solve problems using these resources:
- [SecondThread](https://www.youtube.com/watch?v=G51AjY8tIcA&t=1039s)(Basics of Convex Hull)
- [MATH IF FUN](https://www.mathsisfun.com/algebra/distance-2-points.html)(Basics of Euclidean Distance)
- [Bangladesh Advanced Computing Society - BACS](https://www.youtube.com/watch?v=XMxWarChnZ0)(Many Applications of Convex Hull)
- [CP-Algorithm](https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html)(Implementation of convex hull) 

If you are still stuck with this problem, check the code below:
### C++
```
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pi acos(-1.0)
#define pb push_back
#define pii pair<int,int>
class Point
{
public:
    int x;
    int y;
    Point() {}
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    bool operator < (const Point&p)
    {
        return (x<p.x or (x==p.x and y<p.y));
    }
    bool operator > (const Point & p)
    {
        return ((x > p.x) or (x == p.x && y > p.y));
    }
};
bool cw(Point a,Point b,Point c)
{
    return (a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))<0;
}
bool acw(Point a,Point b,Point c)
{
    return (a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))>0;
}
vector<Point>convex_hull(vector<Point>v)
{
    if(v.size()==1)
        return v;
    sort(v.begin(),v.end());
    int n=v.size();
    Point left=v[0];
    Point right=v[n-1];
    vector<Point>up,down;
    up.pb(left);
    down.pb(left);
    for(int i=1; i<n; i++)
    {
        if(i==n-1 or acw(left,right,v[i]))
        {
            while(up.size()>=2 and !cw(up[up.size()-2],up[up.size()-1],v[i])) 
                up.pop_back();
            up.push_back(v[i]);
        }
        if(i==n-1 or cw(left,right,v[i]))
        {
            while(down.size()>=2 and !acw(down[down.size()-2],down[down.size()-1],v[i]))
                down.pop_back();
            down.push_back(v[i]);
        }
    }
    vector<Point>c_hull;
    ///anticlockwise
    for(int i=0; i<down.size(); i++)
    {
        c_hull.push_back(down[i]);
    }
    for(int i=up.size()-2; i>=1; i--)
    {
        c_hull.push_back(up[i]);
    }
    return c_hull;
}
double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
main()
{
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int n,d;
        cin>>n>>d;
        vector<Point>v;
        map<pii,int>m;
        for(int i=0; i<n; i++)
        {
            int x,y;
            cin>>x>>y;
            m[ {x,y}]++;
            if(m[ {x,y}]==1)
                v.push_back({x,y});
        }
        vector<Point>ans=convex_hull(v);
        int sz=ans.size();
        double perimeter=2*pi*d;
        cout<<"Case "<<k<<": ";
        if(sz==1)
        {
            cout<<perimeter<<endl;
            continue;
        }
        for(int i=0; i<sz; i++)
        {
            int beg=i;
            int last=(i+1)%sz;
            perimeter+=(dist(ans[beg],ans[last]));
        }
        cout<<fixed<<setprecision(7)<<perimeter<<endl;
    }
}
```
