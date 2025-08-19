package LeetCode2348NumberOfZeroFilledSubarrays

func zeroFilledSubarray(nums []int) int64 {
	var result int64 = 0
	var consecutiveZeroCount int64 = 0
	for _, num := range nums {
		if num == 0 {
			consecutiveZeroCount++
			continue
		}
		if consecutiveZeroCount > 0 {
			result += consecutiveZeroCount * (consecutiveZeroCount + 1) / 2
		}
		consecutiveZeroCount = 0
	}
	if consecutiveZeroCount > 0 {
		result += consecutiveZeroCount * (consecutiveZeroCount + 1) / 2
	}
	return result
}
