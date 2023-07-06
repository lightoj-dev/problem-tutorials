# LOJ 1077 - How Many Points?


## Solution
The number of lattice points lying on the segment **A(x1, y1) -> B(x2, y2)** is same for segment **A(0, 0) -> B(x2 - x1, y2 - y1)** because co-ordinate translation doesn't change the relative distance of lattice points from each other.
The number of lattice points will also be equal to that of segment **A(0, 0) -> B(|x2 - x1|, |y2 - y1|)** since sign (+/-) only tells us in which quadrants the segment will fall.
Number of lattice points is length dependent not quadrant dependent.

So, how to calculate the number of lattice points on any segment **A(0, 0) -> B(x, y)** where **x, y >= 0**? The answer is: **gcd(x, y) + 1**. Why?

Suppose, **g = gcd(x, y)** then, all the lattice points are:

**(0 * x/g, 0 * y/g), (1 * x/g, 1 * y/g), . . . . . . . . . . . . . . . , ((g-1) * x/g, (g-1) * y/g), (g * x/g, g * y/g)** total of **(g + 1)** points with integer abscissas and ordinates.

But what's the proof they lie on the segment **AB** and there can't be any other lattice points? 

See: https://math.stackexchange.com/questions/628117/how-to-count-lattice-points-on-a-line

## Complexity
- Time Complexity: O(T * lg(N)). Where N = **max(a, b)** of **gcd(a, b)**. [Check](https://stackoverflow.com/questions/3980416/time-complexity-of-euclids-algorithm) for the time complexity of Euclid's GCD algorithm.
- Memory Complexity: O(1).

## Code

### C++

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    // For fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int ts = 1; ts <= t; ++ts) {
        pair <long long, long long> A, B;
        cin >> A.first >> A.second >> B.first >> B.second;

        cout << "Case " << ts << ": " << __gcd(abs(A.first - B.first), abs(A.second - B.second)) + 1 << '\n';
    }

    return 0;
}
```
