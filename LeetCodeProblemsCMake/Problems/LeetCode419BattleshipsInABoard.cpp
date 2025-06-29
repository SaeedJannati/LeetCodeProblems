//
// Created by saeed on 6/29/25.
//

#include "LeetCode419BattleshipsInABoard.h"
using namespace std;
void Dfs(vector<vector<char>> & board,vector<pair<int,int>>& directions,int height,int width,int row,int col) {
    board[row][col]='0';
    int newRow{};
    int newCol{};
    for (auto & direction:directions) {
        newRow=row+direction.first;
        if (newRow<0 || newRow>=height)
            continue;
        newCol=col+direction.second;
        if (newCol<0 || newCol>=width)
            continue;
        if (board[newRow][newCol]!='X')
            continue;
        board[newRow][newCol]='0';
        Dfs(board,directions,height,width,newRow,newCol);
    }
}
int LeetCode419BattleshipsInABoard::countBattleships( vector< vector<char>> &board) {
    vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int heigth = board.size();
    int width = board[0].size();
    int shipCount{0};
    for(int i=0;i<heigth;i++) {
        for(int j=0;j<width;j++) {
            if(board[i][j] == '0')
                continue;
            if(board[i][j] == '.') {
                board[i][j] = '0';
                continue;
            }
            if(board[i][j] == 'X') {
                board[i][j] = '0';
                shipCount++;
                Dfs(board,directions,heigth,width,i,j);
            }
        }
    }
    return shipCount;
}
