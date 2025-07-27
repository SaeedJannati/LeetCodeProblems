package LeetCode2210CountHillsAndValleysInAnArray

func countHillValley(nums []int) int {
	var lastSlope int64 = 0
	var slope int64 = 0
	previousAmount := nums[0]
	length := len(nums)
	result := 0
	for i := 1; i < length; i++ {
		if nums[i] == previousAmount {
			continue
		}
		slope = int64(nums[i] - previousAmount)
		previousAmount = nums[i]
		if lastSlope*slope < 0 {
			result++
		}
		lastSlope = slope
	}
	return result

}
