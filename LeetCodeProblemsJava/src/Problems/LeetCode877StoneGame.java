package Problems;

public class LeetCode877StoneGame {
    public boolean stoneGame(int[] piles) {
        int length = piles.length;
        int sum = 0;
        int[][] dp = new int[length][length];
        for (int i = 0; i < length; i++) {
            for(int j = i; j < length; j++) {
                dp[i][j]=-1;
            }
        }
        for (int i = 1; i < length; i++) {
            sum += piles[i];
        }
        return getMaxInRange(piles, dp,0, piles.length -1)>sum/2;
    }
    int getMaxInRange(int[] piles,int[][] dp,int start,int end){
        if(start>end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        if(start==end){
            dp[start][end]= piles[start];
            return dp[start][end];
        }
        int result= piles[start]+Math.max(getMaxInRange(piles,dp,start+2,end),getMaxInRange(piles,dp,start+1,end-1));
        result=Math.max(result,piles[end]+ Math.max(getMaxInRange(piles,dp,start+1,end-1),getMaxInRange(piles,dp,start,end-2)));
        dp[start][end]= result;
        return dp[start][end];
    }

}
