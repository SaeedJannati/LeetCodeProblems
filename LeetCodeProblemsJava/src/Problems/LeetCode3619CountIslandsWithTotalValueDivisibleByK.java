package Problems;

public class LeetCode3619CountIslandsWithTotalValueDivisibleByK {
    public int countIslands(int[][] grid, int k) {
        int height=grid.length;
        int width=grid[0].length;
        int[][] directions=new int[][]{{0,1},{0,-1},{1,0},{-1,0}};
        long[] sum=new long[]{0};
        int result=0;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(grid[i][j]==0){
                    continue;
                }
                sum[0]=grid[i][j];
                grid[i][j]=0;
                dfs(grid,directions,height,width,sum,i,j);
                if(sum[0]%k==0){
                    result++;
                }
            }
        }
        return result;
    }
    void dfs(int[][]grid,int[][] directions,int height,int width,long[] sum,int row,int col){
        int newRow,newCol;
        for(var direction:directions){
            newRow=direction[0]+row;
            if(newRow<0 || newRow>=height){
                continue;
            }
            newCol=direction[1]+col;
            if (newCol<0 || newCol>=width){
                continue;
            }
            if(grid[newRow][newCol]==0){
                continue;
            }
            sum[0]+=grid[newRow][newCol];
            grid[newRow][newCol]=0;
            dfs(grid,directions,height,width,sum,newRow,newCol);
        }
    }
}
