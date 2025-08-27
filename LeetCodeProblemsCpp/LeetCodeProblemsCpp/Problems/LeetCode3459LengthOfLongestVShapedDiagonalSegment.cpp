#include "LeetCode3459LengthOfLongestVShapedDiagonalSegment.h"
using namespace std;
int getDesiredValue(int value)
{
    if (value==1)
        return 2;
    if (value==2)
        return 0;
    return 2;
}
int getNextDirection(int dir)
{
    if (dir<3)
        return dir+1;
    return 0;
}
int CalculateMaxLength(vector<vector<int>>& grid,vector<vector<vector<vector<int>>>> & memoisation,vector<pair<int,int>> & directions,int height,int width, int row,int col,int direction,bool turned)
{
    if (memoisation[row][col][direction][turned?1:0]>0)
        return memoisation[row][col][direction][turned?1:0];
    int result=1;
    
    int desiredValue=getDesiredValue(grid[row][col]);
    int newRow=row+directions[direction].first;
    int newCol=col+directions[direction].second;
    if (newRow>=0 &&newRow<height && newCol>=0 && newCol<width)
    {
               if (grid[newRow][newCol]==desiredValue)
               {
                   result+=CalculateMaxLength(grid,memoisation,directions,height,width,newRow,newCol,direction,turned);
               }
    }
    if (turned)
    {
        memoisation[row][col][direction][turned?1:0]=result;
        return memoisation[row][col][direction][turned?1:0];
    }
   int newdirection=getNextDirection(direction);
     newRow=row+directions[newdirection].first;
     newCol=col+directions[newdirection].second;
    if (newRow>=0 &&newRow<height && newCol>=0 && newCol<width)
    {
        if (grid[newRow][newCol]==desiredValue)
        {
             auto newResult= 1+CalculateMaxLength(grid,memoisation,directions,height,width,newRow,newCol,newdirection,true);
            result=max(result,newResult);
        }
    }
    memoisation[row][col][direction][turned?1:0]=result;
    return memoisation[row][col][direction][turned?1:0];
}

int LeetCode3459LengthOfLongestVShapedDiagonalSegment::lenOfVDiagonal(vector<vector<int>>& grid)
{
    vector<pair<int,int>> directions{{-1,-1},{-1,1},{1,1},{1,-1}};
    int height=static_cast<int>( grid.size());
    int width=static_cast<int>( grid[0].size());
    int currentResult=0;
    int maxResult{0};
    vector memoisation(height, vector(width, vector(4, vector(2, 0))));

    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            if (grid[i][j]!=1)
                continue;
            if (maxResult==0)
                maxResult=1;
            for ( int k=0;k<4;k++)
            {
                if (i+directions[k].first<0|| i+directions[k].first >=height || j+directions[k].second<0 || j+directions[k].second>=width)
                    continue;
                currentResult=CalculateMaxLength(grid,memoisation,directions,height,width,i,j,k,false);
                maxResult=max(maxResult,currentResult);
            }
        }
    }
    return maxResult;
}


