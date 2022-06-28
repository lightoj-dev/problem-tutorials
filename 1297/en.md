# LOJ 1297 - Largest Box

+ To solve the problem we need to find a mathematical formula to calculate the volume of the card.

$$
volume(x) = (w - 2x) * (l - 2x) * x
$$

$$
volume(x) = wlx - 2 wx^2 - 2 lx^2 + 4 x^3
$$

+ To get the maximum volume we derive the formula with respect to "x".

$$
   \frac{d volume}{dx} = wl - 4 wx - 4 lx + 12 x^2
$$

$$
   \frac{d volume}{dx} = wl - 4(w + l)x + 12 x^2
$$

+ We make the first derivative equal zero and get solutions for the equation to find the critical points.

$$
\frac{d volume}{dx} = 0
$$

$$
wl - 4(w + l)x + 12 x^2 = 0
$$

+ Solve the equation using the general formula.

$$
x=\frac{-b \pm \sqrt{b^2-4ac}}{2a}
$$

$$
x = \frac{4(w + l) \pm \sqrt{16(w + l)^2 - 4 * 12 * wl}}{24}
$$

$$
x = \frac{4(w + l) \pm \sqrt{16w^2 + 16l^2 + 32wl - 48wl}}{24}
$$

$$
x = \frac{4(w + l) \pm \sqrt{16w^2 + 16l^2 - 16wl}}{24}
$$

$$
x = \frac{4(w + l) \pm 4\sqrt{w^2 +l^2 -wl}}{24}
$$

$$
x = \frac{(w + l) \pm \sqrt{w^2 +l^2 -wl}}{6}
$$


+ We get the second derivative to find the maximum point is when using plus or minus in general formula.

$$
   \frac{d^2 volume}{dx^2} = -4(w + l) + 24 x
$$

+ The maximum point makes second derivative less than zero.

$$
 \frac{d^2 volume}{dx^2} < 0
$$

+ So we use to get maximum

$$
x = \frac{(w + l) - \sqrt{w^2 +l^2 -wl}}{6}
$$


### Code C++
+ Accepted : https://lightoj.com/submission/2360209


```
#include <bits/stdc++.h>
using namespace std;


double calc(double l, double w, double x) {
    return (w-2*x)*(l-2*x)*x;
}

int main(){

    // set precision of the floting digit 6
    cout << fixed << setprecision(6);

    int t;
    cin >> t;
    double w, l;
    for(int i = 1; i <= t; i++) {
        cin >> l >> w;
        cout << "Case " << i << ": ";
        double x = ((w+l) - sqrt(w*w + l*l - w*l))/6;
        cout << calc(l, w, x) << endl;
    }
                
    return 0;
}
```


