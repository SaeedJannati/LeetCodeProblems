package LeetCode976LargestPerimeterTriangle

import "slices"

func largestPerimeter(nums []int) int {
	slices.Sort(nums)
	length := len(nums)
	currentPerimeter := nums[length-1] + nums[length-2] + nums[length-3]
	maxPerimeter := 0
	if nums[length-1] < nums[length-2]+nums[length-3] {
		maxPerimeter = currentPerimeter
	}
	for i := length - 4; i >= 0; i-- {
		currentPerimeter -= nums[i+3]
		currentPerimeter += nums[i]
		if nums[i+2] >= nums[i+1]+nums[i] {
			continue
		}
		maxPerimeter = max(maxPerimeter, currentPerimeter)
	}
	return maxPerimeter
}
