package Problems;

public class LeetCode3665TwistedMirrorPathCount {
    public int uniquePaths(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        long[][][] dp = new long[height][width][2];
        int[][] directions = new int[][]{{0, 1}, {1, 0}};
        int mod = (int) 1e9 + 7;
        int newRow, newCol;
        dp[0][0][0] = 1;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                for (var direction : directions) {
                    newRow = i + direction[0];
                    if (newRow >= height)
                        continue;
                    newCol = j + direction[1];
                    if (newCol >= width)
                        continue;
                    if (grid[i][j] == 0) {
                        if(newRow>i) {
                            dp[newRow][newCol][0]+= dp[i][j][0]+dp[i][j][1];
                            dp[newRow][newCol][0]%=mod;
                            continue;
                        }
                        dp[newRow][newCol][1]+= dp[i][j][0]+dp[i][j][1];
                        dp[newRow][newCol][1]%=mod;
                        continue;
                    }
                    if(newRow>i) {
                        dp[newRow][newCol][0]+= dp[i][j][1];
                        dp[newRow][newCol][0]%=mod;
                        continue;
                    }
                    dp[newRow][newCol][1]+= dp[i][j][0];
                    dp[newRow][newCol][1]%=mod;
                }
            }
        }

        long result= dp[height-1][width-1][0];
        result+=dp[height-1][width-1][1];
        result%=mod;
        return (int)result;
    }
}

