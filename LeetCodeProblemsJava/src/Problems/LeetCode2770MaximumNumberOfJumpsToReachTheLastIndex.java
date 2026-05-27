package Problems;

public class LeetCode2770MaximumNumberOfJumpsToReachTheLastIndex extends BaseProblem {
    public int maximumJumps(int[] nums, int target) {
        int length = nums.length;
        int[] dp = new int[length];
        dp[0] = 0;
        for (int i = 1; i < length; i++) {
            dp[i]=-1;
        }
        for (int i = 1; i < length; i++) {
            for (int j = 0; j < i; j++) {
                if (Math.abs(nums[i] - nums[j]) > target) {
                    continue;
                }
                if (dp[j] == -1) {
                    continue;
                }
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
        return dp[length - 1];
    }

    @Override
    public void Run() {
        int[] nums = new int[]{1, 3, 6, 4, 1, 2};
        int k = 0;
        System.out.println(maximumJumps(nums, k));
    }
}
