package LeetCode2873MaximumValueOfAnOrderedTripletI

import "math"

func Calculate(nums []int) int64 {
	return maximumTripletValue(nums)
}
func maximumTripletValue(nums []int) int64 {
	length := len(nums)
	maxPrefixDelta := make([]int, length)
	maxElementSofar := nums[0]
	maxDelta := 0
	delta := 0
	for i := 1; i < length-1; i++ {
		if nums[i] > maxElementSofar {
			maxElementSofar = nums[i]
		}
		delta = maxElementSofar - nums[i]
		if delta > maxDelta {
			maxDelta = delta
		}
		maxPrefixDelta[i] = maxDelta
	}
	maxElementSofar = math.MinInt
	var result int64 = 0
	var current int64
	for i := length - 1; i > 1; i-- {
		if nums[i] > maxElementSofar {
			maxElementSofar = nums[i]
		}
		nums[i] = maxElementSofar
		current = int64(maxPrefixDelta[i-1]) * int64(nums[i])
		if current > result {
			result = current
		}
	}
	return result
}
