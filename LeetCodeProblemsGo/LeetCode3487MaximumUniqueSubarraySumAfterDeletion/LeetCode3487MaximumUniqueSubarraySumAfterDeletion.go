package LeetCode3487MaximumUniqueSubarraySumAfterDeletion

func maxSum(nums []int) int {
	maxNum := -101
	sum := 0
	numsMap := make(map[int]any)
	for _, num := range nums {
		maxNum = max(num, maxNum)
		if num <= 0 {
			continue
		}
		if _, exists := numsMap[num]; exists {
			continue
		}
		numsMap[num] = struct{}{}
		sum += num
	}
	if maxNum <= 0 {
		return maxNum
	}
	return sum
}
