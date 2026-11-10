package Problems;

public class LeetCode3693ClimbingStairsII {
    public int climbStairs(int n, int[] costs) {
        int[] dp=new int[n+1];
        for(int i=1;i<=n;i++){
            dp[i]=-1;
        }
        return getMinCostOf(costs,dp,n);
    }
    int getMinCostOf(int[] costs, int[] dp,int index){
        if(dp[index]!=-1)
            return dp[index];
        if(index==0){
            dp[index]= 0;
            return 0;
        }
        int cost= Integer.MAX_VALUE ;
        for(int i=1;i<=3;i++){
            if(index<i)
                break;
            cost= Integer.min(cost,getMinCostOf(costs,dp,index-i)+costs[index-1]+i*i);
        }
        dp[index]= cost;
        return cost;
    }
}
