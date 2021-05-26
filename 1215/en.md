# Problem Name: Finding LCM
## [LightOj-1215](https://lightoj.com/problem/finding-lcm)
## Solution Idea:
In this problem, The ` LCM (A, B, C) = L ` and Here ` A , B , L `are known you can find` C `which is the smallest number of all satisfying` C `.

## Solution Approach:

The ` LCM (A, B, C) = L `and ` A, B, L `are known .<br>
Simplify ` LCM (A, B, C) = L ` is ` LCM(LCM(A,B),C)=L `.<br>
Let, ` X= LCM(A,B) `so ` LCM(X, C)=L `<br>
Now, If ` L ` is not divisible by ` X ` then it is impossible to find any` C `.<br> Otherwise find smallest `C` which satisfies `LCM(X, C)=L`.<br>
After expanding the number into the form of prime factor product .<br> 
` GCD (A, B) ` is the smaller exponent of the common prime factors of` A `and` B `in` A `and` B `.<br>
`LCM (A, B)` is the larger exponent of all prime factors of` A `and` B `in` A ` and` B `.<br>
To make` LCM (X,C) = L `, Then the smallest` C `is the prime factor in` L `that is not in` X `and the prime factor in` L `whose index is greater than the index in` X `is taken as the product of the index in` L `.<br>
So now` C `still needs to be multiplied by the common prime factors of` C `and ` X ` to take the exponent in ` X `and takes ` gcd(X,C) ` which takes a small exponential product of ` C ` , ` X ` common prime factors.<br>
When ` GCD(X,C)=1 ` at the same time ` C ` is the smallest prime factor of ` L ` and we will get the smallest ` C `.



# Cpp Code:
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin >> t;
	ll i = 1;
	while (t--)
	{
		ll A, B, L;
		cin >> A >> B >> L;
		ll X = A*B / gcd(A, B);
		if (L % X != 0) cout << "Case " << i++ << ": impossible" << '\n';
		else
		{
			ll C = L / X;
			ll g = gcd(C, X);
			while (g != 1)
			{
				C *= g;
				X /= g;
				g = gcd(C, X);
			}

			cout << "Case " << i++ << ": " << C << '\n';
		}
	}
}

```

Happy Coding!

Written by: [Md. Rasel Meya](https://lightoj.com/user/rhrasel94)