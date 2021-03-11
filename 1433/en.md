# LOJ 1433 - Minimum Arc Distance
---
Tags : euclidean geometry, tri-gonometry

We will be given the _cordinates_ of a circle's center and two _points_ on the _circumference_. We have find out the _arc length_ those two points produce. 

## Solution

To solve it, we first must remember the formula to calculate the [arc length](https://en.wikipedia.org/wiki/Arc_length "arc length") between 2 points of a __circle__, which is 
```
arc length = (radius of the circle) * (angle created by the 2 points at the center of the circle, in radian)
```

To understand this formula in a quick look or to refresh our memories, we can see that the _arc length_ is proportional to the __θ__,_angle created at the center of a circle_. The bigger the _arc length_, the bigger becomes the _angle_ in between the 2 points of the cirlce and vice versa. We can see that the __Circumference__ is the longest arc length of a circle, also we know __C = 2 * π * (radius of the cirlce)__. 
```
C is the arc length when θ = 2 * π
1 is the arc length when θ = (2 * π)/C
                           = (2 * π)/(2 * π *r)
                           = 1/r
S is the arc length when θ = S/r

So, S = θ * r
```

We can calculate the radius of the circle simply by taking the _distanc_ of any _point of a circle_ to its _center_, __distance = √((P1<sub>x</sub> - P2<sub>x</sub>)² + (P1<sub>y</sub> - P2<sub>y</sub>)²)__.

Now to calculate the _angle_ we can use the _cosine rule_ of triangles,
```
AB (Straight line, not the arc length) = √(OA²+OB²-2*OA*OB*cosθ)  
=> AB²  = OA²+OB²-2*OA*OB*cosθ
=> cosθ = (OA²+OB²-AB²)/2*OA*OB
=> θ = arccos ((OA²+OB²-AB²)/2*OA*OB)
```
We again use the _distance_ formula for each line and now we have the necessary values that we can plug into the _arc length_ formula.

The above implementation is `accepted`.

## Solution in C
```c
#include <stdio.h>
#include <math.h>

int main()
{
    int testCases, ox, oy, ax, ay, bx, by;
    scanf("%d", &testCases);
    double OA, OB, AB, angle;
    for (int i = 1; i <= testCases; i++)
    {
        scanf("%d %d %d %d %d %d", &ox, &oy, &ax, &ay, &bx, &by);

        OA = sqrt(pow(ax - ox, 2) + pow(ay - oy, 2));
        OB = sqrt(pow(bx - ox, 2) + pow(by - oy, 2));
        AB = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));

        angle = acos((pow(OA, 2) + pow(OB, 2) - pow(AB, 2)) / (2 * OA * OB));

        printf("Case %d: %.3lf\n", i, OA * angle);
    }
    return 0;
}

```