package Problems;

public class LeetCode3882MinimumXORPathInAGrid {
    public int minCost(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        boolean[][][] dp = new boolean[height][width][1024];
        dp[0][0][grid[0][0]] = true;
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(i==0 && j==0){
                    continue;
                }
                if(i>0){
                    for(int k=0;k<1024;k++){
                        if(!dp[i-1][j][k])
                            continue;
                        dp[i][j][k^grid[i][j]]=true;
                    }
                }
                if(j>0){
                    for(int k=0;k<1024;k++){
                        if(!dp[i][j-1][k])
                            continue;
                        dp[i][j][k^grid[i][j]]=true;
                    }

                }
            }
        }
        for(int i=0;i<1024;i++){
            if(dp[height-1][width-1][i]){
                return i;
            }
        }
        return -1;
    }
}
