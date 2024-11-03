# LOJ 1039 - A Toy Company

---
Tags: Graph Theory, Breadth First Search/Depth First Search

The problem statement has these key points:
1. A word can change in 6 possible ways
2. Some words are forbidden, so need to filter those while traversing
3. Each move costs 1, so bfs can be used to find the minimum path

We need to reach the final word in minimum number of button presses. So first time we reach the final string. is our answer.

## Solution (Key Points)

1. We need three values to define a position, all possible 3 characters combination.
2. We need to check if starting word is forbidden or not before we run bfs.

### Why we need to check starting word beforehand?

Because if we push the node to queue than we will move to another word which might not be forbidden and get results. But if the starting word itself is forbidden than it is impossible to find an answer. We can also check this bofore running the while loop. Similarly, we need to check the final word, but it is taken care of inside the while loop.

## Time Complexity

Building Forbidden Words ->  `O(26 * 26 * 26)` -> O($26 ^{3}$)

Reading Array Values -> O(1)

Array Memset -> O(3 * $26 ^{3}$)

BFS traversal -> O($26 ^{3}$)

Overall Complexity : O(T * 4 * $26 ^{3}$)

## Solution in CPP 

```cpp
/**
 *  @author:   Binoy Barman
 *  @created:  2024-11-03 22:31:02
**/

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define all(v) v.begin(), v.end()
#define Too_Many_Jobs int tts, tc = 1; cin >> tts; hell: while(tts--)
#define Dark_Lord_Binoy ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifdef LOCAL
#include "debug/whereisit.hpp"
#else
#define dbg(...) 42
#endif
#define ll long long

vector<array<int, 3>> moves = {
    {1, 0, 0},
    {-1, 0, 0},
    {0, 1, 0},
    {0, -1, 0},
    {0, 0, 1},
    {0, 0, -1},
};
string st, ed;
array<int, 3> beg, endd;
bool fob[26][26][26], vis[26][26][26];
int dis[26][26][26];

struct Bfs {
    Bfs() {
        memset(fob, 0, sizeof fob); // forbidden words
        memset(vis, 0, sizeof vis); // visited words
        memset(dis, 0, sizeof dis); // distance from starting word
    }
    bool bfs() {
        vis[beg[0]][beg[1]][beg[2]] = true;
        dis[beg[0]][beg[1]][beg[2]] = 0;
        queue<array<int, 3>> q;
        q.push(beg);
        while(!q.empty()) {
            array<int, 3> v = q.front();
            q.pop();
            if(v == endd) return true;
            for(auto move : moves) {
                array<int, 3> u = {
                    (v[0] + move[0] + 26) % 26,
                    (v[1] + move[1] + 26) % 26,
                    (v[2] + move[2] + 26) % 26
                };
                if(!vis[u[0]][u[1]][u[2]] && !fob[u[0]][u[1]][u[2]]) {
                    vis[u[0]][u[1]][u[2]] = true;
                    dis[u[0]][u[1]][u[2]] = 1 + dis[v[0]][v[1]][v[2]];
                    q.push(u);
                }
            }
        }
        return false;
    }
};

int32_t main() {
Dark_Lord_Binoy
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Too_Many_Jobs {
        cin >> st >> ed;
        beg = {st[0] - 'a', st[1] - 'a', st[2] - 'a'};
        endd = {ed[0] - 'a', ed[1] - 'a', ed[2] - 'a'};
        int n;
        cin >> n;
        Bfs g;
        while(n--) {
            string x, y, z;
            cin >> x >> y >> z;
            for(auto i : x) {
              for(auto j : y) {
                for(auto k : z) {
                  array<int, 3> cur = {i - 'a', j - 'a', k - 'a'};
                  fob[cur[0]][cur[1]][cur[2]] = true;
                }
              }
            }
        }
        cout << "Case " << tc++ << ": ";
        if(fob[beg[0]][beg[1]][beg[2]]) {
            cout << -1 << nl;
        } else {
            cout << (g.bfs() ? dis[endd[0]][endd[1]][endd[2]] : -1) << nl;
        }
    }
    
    return 0;
}
```