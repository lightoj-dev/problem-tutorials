# LOJ 1238 - Power Puff Girls
**Problem Statement:** </p> In this problem, we have a 2D grid denoting the home city of the three power puff girls - Blossom, Bubbles and Buttercup. Each cell of the grid is either-
*  '**.**' means an empty place
*  '**a**' denotes the position of Blossom
*  '**b**' denotes the position of Bubbles
*  '**c**' denotes the position of Buttercup
*  '**m**' denotes that there is a monster
*  '**h**' denotes their home
*  '**\#**' denotes a wall and the girls can't pass through it <br> 

The three power puff girls move simultaneously from their initial position. And in each minute, from their current cells, they can move to any four adjacent cells (North, East, West, South) if the destination cell is neither a wall nor the cell contains a monster. <br>

Now, we have to find the **maximum** of the shortest distances from the initial position of each power puff girl to home. In other words, if the shortest distance from the initial postiion of each power puff girl to home is
da, db and dc respectively, then, we have to find the  <br>      max(da, db, dc). <hr /> 
### Solution Idea 1:

Suppose, the shortest distance from the initial postiion of each power puff girl to home is da, db and dc respectively . To calculate the shortest distance between two cell in a 2D grid, we can use **Breadth-first search**. So, to calculate da, db and dc, we have to run bfs three times from the initial position of each power puff girl separately. Each time we will start bfs from the initial position of a different power puff girl and find the shortest distance from that power puff girl to home. After calculating da, db and  dc separately, the final answer will be max(da, db, dc).<br>
See the code below to understand better <br>
### C++
``` c++
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int mxN=25;
char grid[mxN][mxN];
int n,m;
bool valid(int r,int c) {
  return (r>=0 and r<n and c>=0 and c<m and grid[r][c]!='#' and grid[r][c]!='m');
}
bool ppg(char ch) {
  return (ch=='a' or ch=='b' or ch=='c');
}
int bfs(int sx,int sy,int hx,int hy) {
  queue<pair<int,int>>q;
  vector<vector<bool>>used(n,vector<bool>(m));
  vector<vector<int>>dist(n,vector<int>(m));
  q.push({sx,sy});
  used[sx][sy]=true;
  dist[sx][sy]=0;
  while(q.size()) {
    auto cur=q.front();
    q.pop();
    int x=cur.first,y=cur.second;
    for(int i=0;i<4;i++) {
      int tx=x+dx[i];
      int ty=y+dy[i];
      if(!valid(tx,ty) or used[tx][ty]) continue;
      dist[tx][ty]=dist[x][y]+1;
      used[tx][ty]=true;
      q.push({tx,ty});
    }
  }
  return dist[hx][hy];
}
void solve() {
  cin>>n>>m;
  int hx,hy; //initial position of home
  vector<pair<int,int>>pos;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin>>grid[i][j];
      if(grid[i][j]=='h') {
        hx=i,hy=j;
      }
      if(ppg(grid[i][j])) {
        pos.push_back({i,j});
      }
    }
  }
  int da=bfs(pos[0].first,pos[0].second,hx,hy);
  int db=bfs(pos[1].first,pos[1].second,hx,hy);
  int dc=bfs(pos[2].first,pos[2].second,hx,hy);
  int ans=max({da,db,dc});
  cout<<ans<<endl;
}
int main(int argc, char const *argv[]) {
  int test_case;
  cin>>test_case;
  for(int tc=1;tc<=test_case;tc++) {
    cout<<"Case "<<tc<<": ";
    solve();
  }
}
```
> **Time Complexity O(n*m)** <br>
> **Can you solve it in more easier way?**

***
### Solution Idea 2:
Do we really need to run bfs three times? Actually, we can solve this problem using single bfs. Instead of finding the shortest distance from each power puff girl to home, we can find the shortest distance from **home** to each power puff girl using single bfs.
### C++
``` c++
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int mxN=25;
char grid[mxN][mxN];
int n,m;
bool valid(int r,int c) {
  return (r>=0 and r<n and c>=0 and c<m and grid[r][c]!='#' and grid[r][c]!='m');
}
bool ppg(char ch) {
  return (ch=='a' or ch=='b' or ch=='c');
}
void solve() {
  cin>>n>>m;
  int hx,hy;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin>>grid[i][j];
      if(grid[i][j]=='h') {
        hx=i,hy=j;
      }
    }
  }
  queue<pair<int,int>>q;
  vector<vector<bool>>used(n,vector<bool>(m));
  vector<vector<int>>dist(n,vector<int>(m));
  q.push({hx,hy});
  used[hx][hy]=true;
  dist[hx][hy]=0;
  while(q.size()) {
    auto cur=q.front();
    q.pop();
    int x=cur.first,y=cur.second;
    for(int i=0;i<4;i++) {
      int tx=x+dx[i];
      int ty=y+dy[i];
      if(!valid(tx,ty) or used[tx][ty]) continue;
      dist[tx][ty]=dist[x][y]+1;
      used[tx][ty]=true;
      q.push({tx,ty});
    }
  }
  int ans=0;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if(ppg(grid[i][j])) {
        ans=max(ans,dist[i][j]);
      }
    }
  }
  cout<<ans<<endl;
}
int main(int argc, char const *argv[]) {
  int test_case;
  cin>>test_case;
  for(int tc=1;tc<=test_case;tc++) {
    cout<<"Case "<<tc<<": ";
    solve();
  }
}
```
> **Time Complexity O(n*m)**