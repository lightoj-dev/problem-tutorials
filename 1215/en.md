# Problem Name: Finding LCM
## [LightOj-1215](https://lightoj.com/problem/finding-lcm)
## Solution Idea:
In this problem, The ` LCM (A, B, C) = L ` and Here ` A , B , L `are known you can find` C `which is the smallest number of all satisfying` C `.<br>
We know that, <br>
**GCD** of two value is smallest power of their prime factorization.<br>
**LCM** of two value is highest power of their prime factorization. <br>

## Solution Approach:

The ` LCM (A, B, C) = L `and ` A, B, L `are known .<br>
Simplify ` LCM (A, B, C) = L ` is ` LCM(LCM(A,B),C)=L `.<br>
Let, ` X= LCM(A,B) `so ` LCM(X, C)=L `<br>
Now, If ` L ` is not divisible by ` X ` then it is impossible to find any` C `.<br> Otherwise find smallest ` C ` which satisfies ` LCM(X, C)=L `.<br>
We get ` C `  which  prime factors of` X `that do not belong to` L `.<br>
But in order to make ` X / GCD(C, X) * C == L` , we need to find the common prime factor of ` X ` and ` C `, and multiply` C `by the difference of its exponents, so as to guarantee ` X / GCD(C, X) ` Will not eliminate the "useful" prime factors in ` X `.<br>

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