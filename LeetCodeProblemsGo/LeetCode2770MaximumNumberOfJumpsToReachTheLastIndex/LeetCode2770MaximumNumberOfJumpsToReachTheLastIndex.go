package LeetCode2770MaximumNumberOfJumpsToReachTheLastIndex

func maximumJumps(nums []int, target int) int {
	length := len(nums)
	dp := make([]int, length)
	for i := 0; i < length; i++ {
		dp[i] = -1
	}
	dp[0] = 0
	for i := 1; i < length; i++ {
		for j := 0; j < i; j++ {
			if dp[j] == -1 {
				continue
			}
			if (nums[i]-nums[j]) < target || (nums[i]-nums[j]) > target {
				continue
			}
			dp[i] = max(dp[i], dp[j]+1)
		}
	}
	return dp[length-1]
}
