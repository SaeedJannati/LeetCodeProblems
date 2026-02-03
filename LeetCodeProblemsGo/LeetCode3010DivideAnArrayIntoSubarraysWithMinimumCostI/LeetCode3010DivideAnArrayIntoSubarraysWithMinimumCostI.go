package LeetCode3010DivideAnArrayIntoSubarraysWithMinimumCostI

import (
	"slices"
)

func minimumCost(nums []int) int {
	firstNum := nums[0]
	slices.Sort(nums)
	if nums[2] < firstNum {
		nums[2] = firstNum
	}
	return nums[0] + nums[1] + nums[2]
}
