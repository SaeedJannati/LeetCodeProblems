package LeetCode3423MaximumDifferenceBetweenAdjacentElementsInACircularArray

import "math"

func maxAdjacentDistance(nums []int) int {
	length := len(nums)
	var maxDiff int = int(math.Abs(float64(nums[0] - nums[length-1])))
	diff := 0
	for i := 1; i < length; i++ {
		diff = int(math.Abs(float64(nums[i] - nums[i-1])))
		if diff > maxDiff {
			maxDiff = diff
		}
	}
	return maxDiff
}
