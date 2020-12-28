# LOJ 1012 - Guilty Prince

#### This is an easy grid travesing problem.
In this problem,we have a grid of size `W` and `H`.Each cell in the grid consist of land `.` or water `#`.We can't travel through water `#`.So from the initial position `@` ,we have to tell the number of cells we can reach by traveling through land `.`

For this problem we have to learn [DFS](http://www.shafaetsplanet.com/?p=973).

Below picture shows a basic working procedure of **DFS**:

![dfs](https://user-images.githubusercontent.com/32892229/103203367-f00a8580-491e-11eb-9952-3731c8cd3bc6.jpg)

Each cell describes as row `x` and column `y`.As the problem describes we can only move from one cell to its adjacent **LEFT,RIGHT,UP** and **DOWN** cells.So to go from one cell to its adjajent cell we have to do this:
```
Left - (x-1,y)
Right - (x+1,y)
Up - (x,y-1)
Down - (x,y+1)
```

Instead of doing this manually everytime we use **Directional Array** and loop through it.

```
int dx[]={+1,-1,+0,-0}
int dy[]={+0,-0,+1,-1}
```

Now from the starting point `@`,we go to every adjacent cells and check if it is a **valid** cell or not.We have to remember that we can't go outside grid and water cells `#`.For this we can write a valid function to check.

```
bool valid(int x,int y)
{
    if(x>=0 && x<h && y>=0 && y<w && str[x][y]!='#' && !vis[x][y]) return true;
    return false;
}
```

We also make a counter to track how many cells we can visit.

### C++
-----
```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 25;

int dx[]={+1,-1,+0,-0};
int dy[]={+0,-0,+1,-1};

char str[maxn][maxn];
bool vis[maxn][maxn];
int w,h,cnt;

bool valid(int x,int y)
{
    if(x>=0 && x<h && y>=0 && y<w && str[x][y]!='#' && !vis[x][y]) return true;
    return false;
}

void dfs(int i,int j)
{
    vis[i][j]=1;
    cnt++;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(valid(x,y)){
            dfs(x,y);
        }
    }
}

int main()
{
    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&w,&h);
        for(int i=0;i<h;i++){
            scanf("%s",str[i]);
        }
        memset(vis,0,sizeof(vis));
        cnt = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(str[i][j]=='@'){
                    dfs(i,j);
                    break;
                }
            }
        }
        printf("Case %d: %d\n",tc++,cnt);
    }
    return 0;
}
```

### Happy Coding :)
