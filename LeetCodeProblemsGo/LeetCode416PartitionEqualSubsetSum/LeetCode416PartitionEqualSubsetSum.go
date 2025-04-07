package LeetCode416PartitionEqualSubsetSum

import "fmt"

func Calculate(nums []int) {
	fmt.Println(canPartition(nums))
}

func canPartition(nums []int) bool {
	sum := 0
	for _, num := range nums {
		sum += num
	}
	if sum%2 == 1 {
		return false
	}
	length := len(nums)
	target := sum / 2
	dp := make([][]int, target+1)
	for i := 0; i < target+1; i++ {
		dp[i] = make([]int, length+1)
	}
	var previous int
	for j := 1; j < target+1; j++ {
		for i := 1; i < length+1; i++ {
			previous = 0
			if j-nums[i-1] >= 0 {
				previous = dp[j-nums[i-1]][i-1]
			}
			dp[j][i] = previous + nums[i-1]
			if dp[j][i] == target {
				return true
			}
			if dp[j][i-1] > dp[j][i] || dp[j][i] > j {
				dp[j][i] = dp[j][i-1]
			}
		}
	}
	return false
}
