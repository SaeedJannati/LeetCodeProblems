package LeetCode3375MinimumOperationsToMakeArrayValuesEqualToK

import "math"

func minOperations(nums []int, k int) int {
	numsMap := make(map[int]struct{})
	min := math.MaxInt32
	for _, num := range nums {
		numsMap[num] = struct{}{}
		if num < min {
			min = num
		}
	}
	if min < k {
		return -1
	}
	distinctCount := len(numsMap)
	if min == k {
		return distinctCount - 1
	}
	return distinctCount

}
