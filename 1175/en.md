# LOJ 1175 - Jane and the Frost Giants

## Prerequisite
[BFS (Bredth First Search)](https://cp-algorithms.com/graph/breadth-first-search.html)

## Solution
If we forget about the movable fire cells that grows every minute, then the problem reduces to calculating how many minutes it takes to reach a cell without going through an obstacle, which can be done easily with BFS alone.

Taking the fire cells into account, we can think of them as movable osbtacles that expand to the adjacent cells every minute causing *Jane* not to move through them. Consider the first instance of the grid where the **#** cells are entirely obstacles that can't move versus **F** cells, all of which shows the same feature as the **#** cells (can't move through them) but also in the next instance all the adjacent cells of each **F** cell will become new **F** cells aka, 'movable obstacles' repeating the same procedure. So, we have to keep track of **F** cells coverage as well as *Jane's* parallely.

Point to be noted: At every instance, before *Jane* moves to any of her adjacent cells, the **F** cells must move to their adjacent cells, because *Jane* can only move through that cell if the fire hasn't lit up in that very moment. 

## Complexity
- Time Complexity: O(T * R * C).
- Memory Complexity: O(R * C).

## Code

### C++

```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits <int>:: max(); // Indicating Unreachable state

int r, c;
vector <string> grid;

// An Efficient (and quite common) Way to Navigate Grid Problems: https://codeforces.com/blog/entry/78827
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

inline bool valid(int x, int y) {
    // 0-based index grid
    return x >= 0 && x < r && y >= 0 && y < c && grid[x][y] != '#';
}

struct Cell {
    bool flag; // Indicating whther this cell is on fire or not
    int x, y; // Row and column respectively 

    Cell() {} // Default constrcutor
    Cell(bool flag, int x, int y) : flag(flag), x(x), y(y) {}
};

int main() {
    
    // For fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int ts = 1; ts <= t; ++ts) {
        cin >> r >> c;

        grid.resize(r);
        
        pair <int, int> source;
        queue <Cell> Q;
        // dist[i][j] = Minimum minutes needed to move to cell[i][j] from starting cell
        vector <vector <int>> dist(r, vector <int> (c, INF));
        for(int i = 0; i < r; ++i) {
            cin >> grid[i];
            for(int j = 0; j < c; ++j) {
                if (grid[i][j] == 'J') {
                    source = {i, j};
                }
                else if (grid[i][j] == 'F') {
                    // Turning into a movable obstacle
                    grid[i][j] = '#';
                    Q.push(Cell(true, i, j));
                }
            }
        }

        // All the fire cells have been added to the queue so that they always move to the adjacent cells first not, Jane
        dist[source.first][source.second] = 0;
        Q.push(Cell(false, source.first, source.second));
        
        while (!Q.empty()) {
            Cell u = Q.front(); 
            Q.pop();

            for(int i = 0; i < 4; ++i) {
                int x = u.x + dr[i];
                int y = u.y + dc[i];
             
                // Checking for not an obstacle yet
                if (valid(x, y) && dist[x][y] == INF) {
                    if (u.flag) {
                        // Now an obstacle that can move
                        grid[x][y] = '#';
                        Q.push(Cell(true, x, y));
                    }
                    else {
                        // That's jane moving
                        dist[x][y] = dist[u.x][u.y] + 1;
                        Q.push(Cell(false, x, y));
                    }
                }
            }
        }
        
        int best = INF;
        // Topmost and downmost rows
        for(int j = 0; j < c; ++j) {
            best = min({best, dist[0][j], dist[r-1][j]});
        }
        // Leftmost and rightmost columns
        for(int i = 0; i < r; ++i) {
            best = min({best, dist[i][0], dist[i][c-1]});
        }

        cout << "Case " << ts << ": ";

        if (best == INF) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            // Adding 1 because of getting out of the maze completely
            cout << best+1 << '\n'; 
        }

        grid.clear();
    }

    return 0;
}
```
