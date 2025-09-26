package LeetCode611ValidTriangleNumber

import "slices"

func triangleNumber(nums []int) int {
	length := len(nums)
	slices.Sort(nums)
	lastK := 0
	result := 0
	sum := 0
	for i := 0; i < length-2; i++ {
		if nums[i] == 0 {
			continue
		}
		lastK = i + 2
		for j := i + 1; j < length-1; j++ {
			sum = nums[i] + nums[j]
			for lastK < length && nums[lastK] < sum {
				lastK++
			}
			result += lastK - j - 1
		}
	}
	return result
}
