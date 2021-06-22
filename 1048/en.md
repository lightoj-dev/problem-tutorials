## Problem Restatement. 

We Have an Array ```a``` of ```n+1``` elements, and in that we want to mark ```k``` points. And the output of this problem is the function

```
f(a,v) = max(v[i + 1] - v[i]) over all i in set of marked indices.
```

Our objective is to minimize ```f​```. 

### Analysis.

Let us make the problem easier, and instead of having exactly $k$, we compute the function for atmost $k$. With this structure, we create new boolean function ```g(x) = (f(a,k) <= x)​```

Observe that this function is monotonic. As for if there exists $x$ where it's true, for all ```y >= x , g(y) = 1``` will be true as well. Hence we can apply binary search on ```g​``` to find the optimal ```x```​. 

To check if a ```x``` satisfies a condition, we can greedily pick the longest route possible from the starting position, and repeat this till the end. 

The proof is by exchange arguments. As if in the the optimal solution the initial path is not the longest possible, extending it will maintain its optimality. Hence we can recurse on the sub-problem using the same principle. 

```c++
   	  bool g(int mid) {
            vector<int> now;
            int curr = 0;
            int walked = 0;
            for(int &x : v) {
                  if(walked + x > mid) {
                        now.push_back(walked);
                        if(++curr > k)
                              return false;
                        walked = x;
                  }
                  else
                        walked += x;
                  
            }
            now.push_back(walked);
          	// This is the answer vector for printing
            answer = now; 
            return true;
      };
```



Now all that is left is to make the number of nights exactly equal to ```k```. For that we can simply break down the non-consecutive successive indices to increment the number of nights. 

```c++
      int df = k + 1 - sz(answer);
      vector<int> vec;
      while(df > 0) {
            int b = v.back();
            v.pop_back();
            vec.push_back(b);
            answer.back() -= b;
            if(answer.back() == 0) 
                  answer.pop_back();
            else
                  --df;
      }
```

 

Finally, what is left is to print the solution.

Here is the full code.

```c++
#include<bits/stdc++.h>
using namespace std;
#define A(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

void test() {
      int n,k;
      cin >> n >> k;
      vector<int> v(n + 1);
      for(int &x : v)
            cin >> x;
      vector<int> answer;
      int lo = * max_element(A(v)) , hi = accumulate(A(v),0), ans = -1;


      auto ok = [&](int mid) {
            vector<int> now;
            int curr = 0;
            int walked = 0;
            for(int &x : v) {
                  if(walked + x > mid) {
                        now.push_back(walked);
                        if(++curr > k)
                              return false;
                        walked = x;
                  }
                  else
                        walked += x;
                  
            }
            now.push_back(walked);
            answer = now;
            return true;
      };


      while(hi >= lo) {
            int mi = (hi + lo) >> 1;
            if(ok(mi))
                  ans = mi, hi = mi - 1;
            else
                  lo = mi + 1;
      }
      ok(ans);
      cout << ans << '\n';
      int df = k + 1 - sz(answer);
      vector<int> vec;
      while(df > 0) {
            int b = v.back();
            v.pop_back();
            vec.push_back(b);
            answer.back() -= b;
            if(answer.back() == 0) 
                  answer.pop_back();
            else
                  --df;
      }
      reverse(A(vec));
      for(int x : vec)
            answer.push_back(x);
      for(int &x : answer)
            cout << x << '\n';
}
int main () {
      ios_base :: sync_with_stdio(false);
      cin.tie(NULL);
      int T = 1;
      cin >> T;
      for( int tt = 1; tt <= T; tt++) {
            cout << "Case " << tt << ": ";
            test();
      }
      return 0;
};

```

