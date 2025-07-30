package LeetCode2419LongestSubarrayWithMaximumBitwiseAND

func longestSubarray(nums []int) int {
	maxNum := 0
	for _, num := range nums {
		maxNum = max(maxNum, num)
	}
	consecutiveCount := 0
	maxConsecutiveCount := 0
	for _, num := range nums {
		if num == maxNum {
			consecutiveCount++
			continue
		}
		maxConsecutiveCount = max(maxConsecutiveCount, consecutiveCount)
		consecutiveCount = 0
	}
	maxConsecutiveCount = max(maxConsecutiveCount, consecutiveCount)
	return maxConsecutiveCount
}
