# LightOJ - 1377 - Blade and Sword

## Problem Summary
* We are given a 2d maze and we have to reach from 'P' to 'D' using minimum move possible. 
* if we find portal on the way. we have to continue form other portal.

## Solution Idea
Here we will mainly use `Priority Queue` to solve this problem. 
* We have to mark all portal ('*') in a vector list.  
* Create data type (struct) to keep track mark and minimum distance.
* Start priority queue from 'P'. when you get a portal ('*') with distance d, mark all other the portal d+2 (if other portal exists) and all other portal d+1. also push them in the queue. it will be wise if you keep track on the min distance for these portal. So that you dont have to count all of them agian and again.


## Code in C++
```
#include <bits/stdc++.h>
#define FORN(i, n)              for(int i = 0; i < n; i++)
#define xx                      first
#define yy                      second
#define PII                     pair<int, int>
#define BOUNDARY(i, j, r , c)   ((i >= 0 && i < r) && (j >= 0 && j < c))
using namespace std;
#define SIZE                (int)250
/*----------------------Graph Moves----------------*/
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
/*------------------------------------------------*/
struct data {
    int x, y, d ;
    data(int _x , int _y , int _d)
    {
        x= _x ;
        y = _y ;
        d = _d ;
    }
    data(){}
};
// this is for getting minimum distance first in priority queue
bool operator < (data a , data b)
{
    return a.d > b.d ;
}
string maze[SIZE] ;
int n , m;
int dist[SIZE][SIZE] ;
int solve()
{
    priority_queue <data> q ;
    vector <PII> v ;
    data st ;
    bitset <SIZE> vis[SIZE] ;
    
    cin >> n >> m ;
    FORN(i,n){
        cin >> maze[i] ;
        vis[i].reset() ;
        FORN(j,m){
            if (maze[i][j] == 'P' ) st.x = i , st.y = j ;
            else if (maze[i][j] == '*') v.push_back({i,j}) ;
            else if (maze[i][j] == '#') vis[i][j] = 1 ;
            dist[i][j] = INT_MAX ;
        }
    }
    st.d = 0 ;
    q.push(st) ;
    dist[st.x][st.y] = 0 ;
    while(!q.empty())
    {
        int x = q.top().x ;
        int y = q.top().y ;
        int d = q.top().d ;
        q.pop() ;
        if (dist[x][y] != d) continue ;
        if (maze[x][y] == 'D') return d ;
        
        
        vis[x][y] = 1 ;
        
        FORN(k,4)
        {
            int xx = x + fx[k] ;
            int yy = y + fy[k] ;
            if (!BOUNDARY(xx,yy,n,m)) continue ;
            if (vis[xx][yy]) continue ;
            if (maze[xx][yy] == '*')
            {
                for (auto i : v)
                {
                    if (i == PII{xx,yy}) continue ;
                    if (dist[i.xx][i.yy] > d+2){
                    // wa2(i.xx,i.yy) ;
                        dist[i.xx][i.yy] = d+2 ;    
                        q.push(data(i.xx,i.yy,d+2)) ;
                    }
                   if (dist[xx][yy] > d+3){
                        dist[xx][yy] = d+3 ;
                        q.push(data(xx,yy,d+3)) ;
                    }
                }
            }
            else if (dist[xx][yy] > d+1){
                dist[xx][yy] = d+1 ;
                q.push(data(xx,yy,d+1)) ;
            }
            
        }
    }
    return INT_MAX ;
}
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testCase = 1 ;cin >> testCase ;
    for (int i = 0; i < testCase; i++){
        cout << "Case " << i+1 << ": "  ;
        int res = solve() ;
        if(res == INT_MAX) cout << "impossible\n" ;
        else cout << res << "\n" ;
    }
        
}
```
