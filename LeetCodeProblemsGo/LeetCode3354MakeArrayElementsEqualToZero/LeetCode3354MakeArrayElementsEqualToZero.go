package LeetCode3354MakeArrayElementsEqualToZero

func countValidSelections(nums []int) int {
	length := len(nums)
	prefixSum := make([]int, length)
	suffixSum := make([]int, length)
	for i := 1; i < length; i++ {
		prefixSum[i] = prefixSum[i-1] + nums[i-1]
	}
	for i := length - 2; i >= 0; i-- {
		suffixSum[i] = suffixSum[i+1] + nums[i+1]
	}
	validCount := 0
	for i := 0; i < length; i++ {
		if nums[i] != 0 {
			continue
		}
		if prefixSum[i] == suffixSum[i] {
			validCount += 2
			continue
		}
		if (prefixSum[i]-suffixSum[i]) == 1 || (suffixSum[i]-prefixSum[i]) == 1 {
			validCount += 1
		}
	}
	return validCount
}
