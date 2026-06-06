package LeetCode2574LeftAndRightSumDifferences

import "math"

func leftRightDifference(nums []int) []int {
	length := len(nums)
	left := make([]int, length)
	right := make([]int, length)
	for i := 1; i < length; i++ {
		left[i] = left[i-1] + nums[i-1]
		right[length-i-1] = right[length-i] + nums[length-i]
	}
	for i := 0; i < length; i++ {
		nums[i] = int(math.Abs(float64(left[i] - right[i])))
	}
	return nums
}
