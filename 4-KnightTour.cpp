/*
    There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and 
    visits every cell on the board exactly once.You are given an n x n integer matrix grid consisting of distinct integers 
    from the range [0, n * n - 1] where grid[row][col] indicates that the cell (row, col) is the grid[row][col]th cell that the knight visited. 
    The moves are 0-indexed.
    Return true if grid represents a valid configuration of the knight's movements or false otherwise.
    Note that a valid knight move consists of moving two squares vertically and one square horizontally, 
    or two squares horizontally and one square vertically. The figure below illustrates all the possible eight moves of a knight from some cell.
*/
#include<iostream>
#include<vector>
using namespace std;

bool nextValidPos(vector<vector<int>>& grid, int &i, int &j, int count){

    if(i-1 >= 0 && j-2 >= 0 && count == grid[i-1][j-2]){
        i = i - 1;
        j = j - 2;
        return true;
    }else if(i-1 >= 0 && j+2 < grid[0].size()  && count == grid[i-1][j+2]){
        i = i - 1;
        j = j + 2;
        return true;

    }else if(i+1 < grid[0].size() && j+2 < grid[0].size() && count == grid[i+1][j+2]){
        i = i + 1;
        j = j + 2;
        return true;

    }else if(i+1 < grid[0].size() && j-2 >= 0 && count == grid[i+1][j-2]){
        i = i + 1;
        j = j - 2;
        return true;

    }else if(i-2 >= 0 && j-1 >= 0 && count == grid[i-2][j-1]){
        i = i - 2;
        j = j - 1;
        return true;
    }else if(i-2 >= 0 && j+1 < grid[0].size()  && count == grid[i-2][j+1]){
        i = i -2;
        j = j + 1;
        return true;

    }else if(i+2 < grid[0].size() && j+1 < grid[0].size() && count == grid[i+2][j+1]){
        i = i + 2;
        j = j + 1;
        return true;

    }else if(i+2 < grid[0].size() && j-1 >= 0 && count == grid[i+2][j-1]){
        i = i + 2;
        j = j -1;
        return true;

    }
    return false;
}

bool checkValidGrid(vector<vector<int>>& grid) {
    int i = 0, j = 0, len = grid.size();

    for(int x=1; x<(len*len); x++){
        if(!nextValidPos(grid, i, j,x)){
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> grid;

    vector<int> fst{0,11,16,5,20};
    grid.push_back(fst);

    vector<int> sec{17,4,19,10,15};
    grid.push_back(sec);

    vector<int> trd{12,1,8,21,6};
    grid.push_back(trd);

    vector<int> four{3,18,23,14,9};
    grid.push_back(four);

    vector<int> fth{24,13,2,7,22};
    grid.push_back(fth);

    cout<<checkValidGrid(grid);

    return 0;
}