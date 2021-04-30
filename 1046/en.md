# LOJ 1046 - Rider

#### This is a grid travesing problem.
In this problem,We have a grid of size `m` and `n`. Each cell consists of `.` (empty cell) or integers between `1 to 9`.<br>
We have a special kind of knights that can jump multiple times in a single move. If a cell consists of integer `k` it means that the knights can jump
`k` times in a single move.

Knights can jump `8` different directions :
```
(x+1, y+2), 
(x+1, y-2), 
(x+2, y+1), 
(x+2, y-1), 
(x-1, y+2), 
(x-1, y-2), 
(x-2, y+1), 
(x-2, y-1)
```
Knights can move through `.` empty cells and the cells that already consists a knight. So multiple knights can stay same cell at a time.<br>
Now we need to tell what is the minimal total number of moves necessary to move all the knights to the same cell.

For each cell we need to know how many moves each knights need to reach that cell.<br>

So from each knights we run a [bfs](shafaetsplanet.com/?p=604) to traverse the whole grid and count the minimum move it needs to reach every cell.<br>
Instead of doing knights movement manually everytime we can use [Directional Array](https://www.shafaetsplanet.com/?p=1448) and loop through it.<br>
```
int dx[] = {+1,+1,+2,+2,-1,-1,-2,-2};
int dy[] = {+2,-2,+1,-1,+2,-2,+1,-1};
```
Lastly, For each cell we check if this cell is reachable for all knights and if its reachable we take the summation of all knights moves.<br>
Answer will be the minimum summation among all cells.

<details>
  <summary> <b>Code : </summary>
  <br>
  
  ### C++
  -----
  ```cpp
  #include<bits/stdc++.h>
  #define ll long long
  #define ff first
  #define ss second
  using namespace std;

  int dx[] = {+1,+1,+2,+2,-1,-1,-2,-2};
  int dy[] = {+2,-2,+1,-1,+2,-2,+1,-1};

  char str[15][15];
  int m,n;
  int dis[105][15][15],step[105];

  bool valid(int x,int y)
  {
      if(x >= 0 && x < m && y >= 0 && y < n) return true;
      else return false;
  }

  int main()
  {
      int t,tc=1;
      scanf("%d",&t);
      while(t--){
          scanf("%d %d",&m,&n);
          for(int i = 0;i < m;i++) scanf("%s",str[i]);
          vector<pair<int,int> >knights;
          int cnt = 0;
          for(int i = 0;i < m;i++){
              for(int j = 0;j < n;j++){
                  if(str[i][j] >= '1' && str[i][j] <= '9'){
                      step[cnt++] = str[i][j] - '0';
                      knights.push_back({i,j});
                  }
              }
          }
          for(int i = 0;i < knights.size();i++){
              for(int j = 0;j < m;j++){
                  for(int k = 0;k < n;k++){
                      dis[i][j][k] = 1e9;
                  }
              }
              queue<pair<int,pair<int,pair<int,int> > > >q;
              q.push({1,{step[i]-1,{knights[i].ff,knights[i].ss}}});
              dis[i][knights[i].ff][knights[i].ss] = 0;
              while(!q.empty()){
                  pair<int,pair<int,pair<int,int> > > pr = q.front();
                  q.pop();
                  int d = pr.ff;
                  int s = pr.ss.ff;
                  int x = pr.ss.ss.ff;
                  int y = pr.ss.ss.ss;
                  for(int j = 0;j < 8;j++){
                      int xx = x + dx[j];
                      int yy = y + dy[j];
                      if(valid(xx,yy)){
                          if(d < dis[i][xx][yy]){
                              dis[i][xx][yy] = d;
                              if(s == 0) {
                                  q.push({d+1,{step[i]-1,{xx,yy}}});
                              }
                              else q.push({d,{s-1,{xx,yy}}});
                          }
                      }
                  }
              }
          }
          ll ans = 1e9;
          for(int i = 0;i < m;i++){
              for(int j = 0;j < n;j++){
                  ll mx = 0;
                  for(int k = 0;k < knights.size();k++){
                      mx += dis[k][i][j];
                  }
                  ans = min(ans,mx);
              }
          }
          if(ans == 1e9) ans = -1;
          printf("Case %d: %lld\n",tc++,ans);
      }
      return 0;
  }
  ```
</details>

### Happy Coding :)
