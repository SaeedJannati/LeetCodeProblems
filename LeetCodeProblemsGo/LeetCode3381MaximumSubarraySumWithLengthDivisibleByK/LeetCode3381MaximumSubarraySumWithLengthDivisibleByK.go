package LeetCode3381MaximumSubarraySumWithLengthDivisibleByK

import "math"

func maxSubarraySum(nums []int, k int) int64 {
	length := len(nums)
	prefixSums := make([]int64, length)
	for i := 1; i < length; i++ {
		prefixSums[i] = prefixSums[i-1] + int64(nums[i-1])
	}
	var maxSum int64
	var currentSum int64
	maxSums := make([]int64, length)
	for i := 0; i < length; i++ {
		maxSums[i] = math.MinInt64
	}
	maxSums[k-1] = prefixSums[k-1] + int64(nums[k-1])
	maxSum = maxSums[k-1]
	for i := k; i < length; i++ {
		currentSum = prefixSums[i] - prefixSums[i-k+1] + int64(nums[i])
		if maxSums[i-k] == math.MinInt64 {
			maxSums[i] = currentSum
		} else {
			maxSums[i] = max(currentSum, currentSum+maxSums[i-k])
		}
		maxSum = max(maxSum, maxSums[i])
	}
	return maxSum
}
