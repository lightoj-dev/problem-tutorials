# LOJ 1216 - Juice in the Glass #
---
Once upon a time, there lived a mad programmer. He loved to solve creative problems other than anything. His wife loved him quite a lot but disliked his curiosity for the problems. One day he came from office, his wife gave him a glass of cold lime juice. She was in a romantic mood and waiting for some romantic stuff. But the programmer asked her curiously, "If I give u radius of the top and bottom part of the glass and the height, can you come up with the volume of the glass?" His wife became a bit disappointed but as she is smart she replied with a smile, "You already have drunk some juice, and the glass is not full. If I give you the height of the juice, can you find the volume of the remaining juice in the glass?" Then the programmer kissed his wife and said, "You are the best problem setter in the world!"

<p align = "center"><img src="problem1216.png"></p>

Now he set the same problem for you. The radius of the upper part _r1_ and lower part _r2_ is given. If height of the glass is _h_ and height of the juice is _p_ what is the volume of the juice in the glass?

### Input

Input starts with an integer __T (≤ 100)__, denoting the number of test cases.

Each case starts with a line containing four integers __r1 r2 h p (1 ≤ r2 < r1 ≤ 100, 1 ≤ p ≤ h ≤ 100)__.

### Output

For each case, print the case number and the volume of the juice in the glass. __Errors less than 10<sup>-6</sup> will be ignored.__

## Solution

<p align = "center"><img src="1216.png" height ="350" ></p>

To solve it, me must know how to calculate the volume of a [Conical Frustum](https://en.wikipedia.org/wiki/Frustum "Conical Frustum").

The `volume of a conical frustum, V = (π/3) * height * (radius1² + radius2² + (radius1 * radius2))`. So, if we know the 2 values of the __radii__, we can calculate __volume of the juice__. The only thing we need to figure out is, what is `r3`, the `radius` of glass at point `p`. Since, already `r2` and `r1` is given, we can find out the value of `r3` by doing some __tri-gonometric__ calculations.

In the figure:
```
In △EGC, 
    tan(α) = EG/EC
           = (r1-r2)/h ...(i)

In △MNC,
    tan(α) = MN/MC
           = (r3-r2)/p
    => r3 - r2 = p*tan(α)
    => r3 = p*tan(α) + r2 
          = p*(r1-r2)/h + r2 [From, (i)] 
```
Now we can just simply plugin the value of `r3` in our formula, `V = (π/3) * p * (r3² + r2² + (r3 * r2))`.

The above solution is `accepted`.

## Solution in C ##

```c
#include <stdio.h>
#include <math.h>

int main()
{
    double pi, r3;
    pi = 2.0*acos(0.0);
    int t, r1, r2, h, p;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d %d %d %d", &r1, &r2, &h, &p);
        r3 = p/(h * 1.0) * (r1 - r2)  + r2;
        printf("Case %d: %.10lf\n", i, (pi / 3.0) * p * (r3 * r3 + r2 * r2 + (r3 * r2)));
    }
    return 0;
}
```