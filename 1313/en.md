# LightOJ 1313 - Protect the Mines

_Keywords: Convex-Polygons, Shortest-Path_

<!-- TODO: write statement -->

### Solution

<!-- TODO: write solution -->

### C++ Code:

```cpp
#include <bits/stdc++.h>

using namespace std;

typedef int Ti;

const int inf = 0x3f3f3f3f;

typedef struct Pt {
	Ti x, y;
	Pt(Ti x = 0, Ti y = 0) : x(x), y(y) { }

	bool operator < (const Pt& p) const { return x == p.x ? y < p.y : x < p.x; }
	bool operator == (const Pt& p) const { return x == p.x and y == p.y; }

	Pt operator - (const Pt& p) const { return Pt(x - p.x, y - p.y); }
} Vec;

Ti cross(Vec a, Vec b) { return a.x * b.y - a.y * b.x; }

int ccw(Pt a, Pt b, Pt c) { return clamp(cross(b - a, c - a), -1, 1); }

typedef vector<Pt> Poly;

Poly convex_hull(Poly p) {
	sort(p.begin(), p.end());
	Poly h;
	for(int i = 0; i < 2; ++i) {
		auto k = h.size();
		for(Pt pt : p) {
			while(h.size() > k + 1 and ccw(h[h.size() - 2], h.back(), pt) <= 0)
				h.pop_back();
			h.push_back(pt);
		}
		h.pop_back();
		reverse(p.begin(), p.end());
	}
	return h;
}

int point_in_convex_polygon(Pt o, const Poly& p) {
	int n = p.size(), l = 1, r = n - 1;
	while(l + 1 < r) {
		int m = (l + r) / 2;
		if(ccw(p[0], p[m], o) > 0) l = m;
		else r = m;
	}
	int d1 = ccw(p[0], p[l], o), d2 = ccw(p[l], p[r], o), d3 = ccw(p[r], p[0], o);
	if(d1 < 0 or d2 < 0 or d3 < 0) return 1;	// OUTSIDE
	if(o == p[0] or !d2 or (l == 1 and !d1) or (r == n - 1 and !d3)) return 0;	// ON PERIMETER
	return -1;	// INSIDE
}

bool points_on_left(const Poly& p, Pt a, Pt b) {
	for(const Pt& pt : p) {
		if(ccw(a, b, pt) < 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, tc = 0;
	cin >> t;

	while(t--) {
		int n, m, guard_cost, pole_cost;
		cin >> n >> m >> guard_cost >> pole_cost;

		Poly p(n), mines(m);
		for(Pt& pt : p) cin >> pt.x >> pt.y;
		for(Pt& pt : mines) cin >> pt.x >> pt.y;

		int res = 0;

		Poly outer = convex_hull(p);
		Poly inner;
		for(const Pt& pt : mines) {
			if(point_in_convex_polygon(pt, outer) > 0) {
				res += guard_cost;
			}
			else {
				inner.push_back(pt);
			}
		}

		if(!inner.empty()) {
			inner = convex_hull(inner);
			vector<vector<int>> d(n, vector<int>(n, inf));

			for(int i=0; i<n; ++i) {
				for(int j=0; j<n; ++j) {
					if(i != j and points_on_left(inner, p[i], p[j])) {
						d[i][j] = 1;
					}
				}
			}

			for(int k=0; k<n; ++k) {
				for(int i=0; i<n; ++i) {
					for(int j=0; j<n; ++j) {
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}

			int poles = inf;
			for(int i=0; i<n; ++i) poles = min(poles, d[i][i]);
			res += poles * pole_cost;
		}

		cout << "Case " << ++tc << ": " << res << "\n";
	}

	return 0;
}
```

---

_[reborn++](https://lightoj.com/user/rebornplusplus)_ <br/>
_May 2, 2021_
