package LeetCode2044CountNumberOfMaximumBitwiseORSubsets

func Backtrack(nums []int, length, targetOrProduct, currentOr, startIndex int, result *int) {
	if currentOr == targetOrProduct {
		*result++
	}
	for i := startIndex + 1; i < length; i++ {
		Backtrack(nums, length, targetOrProduct, currentOr|nums[i], i, result)
	}
}
func countMaxOrSubsets(nums []int) int {
	orProduct := 0
	for _, num := range nums {
		orProduct |= num
	}
	result := 0
	Backtrack(nums, len(nums), orProduct, 0, -1, &result)
	return result
}
