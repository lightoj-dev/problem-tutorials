# Sudoku Solver

###### Helpful Resources:

[Sudoku Solver Geeks For Geeks](https://www.geeksforgeeks.org/sudoku-backtracking-7/)

[Understanding Sudo solves in CPP](https://www.youtube.com/watch?v=lIOupNAafT0)

[Introduction to Backtracking](https://www.youtube.com/watch?v=DKCbsiDBN6c)

###### Solution Approach

Firstly we implement a basic sudoku solver with four important points:

1)We first have to find the empty positions for that we have the findEmptyLocation function

2) To solve a sudoku we have to place a number at an empty position denoted by '.' in this question

3) We use the isSafe function here to determine whether it is safe to place a particular number

4) If empty location found, we iterate from 1 to 9 and try to place that number in that empty position, checking whether it is safe to place the value in each iteration

5) If the empty positions are such that the number of values that needs to be placed exceeds 9 for the given set of isSafe conditions which means we can't just place 1 to 9, then we can conclude that the Sudoku is not solvable and the empty positions remain as 0 denoting that it cannot be filled

To summarise,

In each iteration, we find an empty location. At the empty location, we place a value absent from the same row, box and column, and check if the current state of board can be solved. If it cannot be solved, we place 0 in the empty positions, otherwise we place the appropriate value and finally print the final state of the sudoku matrix.


Note: This is a classic backtracking problem, it does not require dynamic programming approach, it cannot be solved simply by a naive brute force solution.


## Solution in C++
```cpp
#include<bits/stdc++.h>
using namespace std;
#define N 9

int grid[N][N];

bool isSafeInRow(int& row,int value){
    for(int i=0;i<N;i++){
        if(grid[row][i]==value){
            return false;
        }
    }
    return true;
}

bool isSafeInCol(int& col,int value){
    for(int i=0;i<N;i++){
        if(grid[i][col]==value){
            return false;
        }
    }
    return true;
}

bool isSafeBox(int& row,int& col, int value){
    int rowFactor=row-row%3;
    int colFactor=col-col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+rowFactor][j+colFactor]==value){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int& row,int& col,int value){
    if(isSafeInRow(row,value) && isSafeInCol(col,value) && isSafeBox(row,col,value)){
        return true;
    }
    return false;
}

bool findEmptyLocation(int& x,int& y){
    int Min=10,cnt=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(grid[i][j]==0){
                int cnt=0;
                for(int k=1;k<=9;k++)
                {
                    if (isSafe(i,j,k))
                        cnt++;
                }
                if(cnt<Min)
                {
                    Min=cnt;
                    x=i;
                    y=j;
                }
            }
        }
    }
    if(Min<10)
        return true;
    return false;
}



bool solveSudoku(){
    int row,col;
    if(!findEmptyLocation(row,col)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(isSafe(row,col,i)){
            grid[row][col]=i;
            if(solveSudoku()){
                return true;
            }
            grid[row][col]=0;
        }
    }
    return false;
}

void solve(){
    string inp[N];
    string s;
    getline(cin,s);
    for(int i=0;i<N;i++){
        getline(cin,inp[i]);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(inp[i][j]=='.'){
                grid[i][j]=0;
            }
            else grid[i][j]=inp[i][j]-'0';
        }
    }
    solveSudoku();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}



int main(void){
    int t;
    cin>>t;
    cin.ignore();
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": "<<endl;
        solve();
    }
    return 0;
}

```
