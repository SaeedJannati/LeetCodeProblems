package LeetCode2444CountSubarraysWithFixedBounds

import "math"

func countSubarrays(nums []int, minK int, maxK int) int64 {
	ranges := []int{}
	length := len(nums)
	ranges = append(ranges, -1)
	max := math.MinInt
	min := math.MaxInt
	for i := 0; i < length; i++ {
		if nums[i] > maxK || nums[i] < minK {
			ranges = append(ranges, i)
		}
		if nums[i] > max {
			max = nums[i]
		}
		if nums[i] < min {
			min = nums[i]
		}
	}
	if min > minK {
		return 0
	}
	if max < maxK {
		return 0
	}
	ranges = append(ranges, length)
	rightClosestMinMax := make([][]int, length+1)
	var result int64 = 0
	largerLimit := 0
	rightMin := 0
	rightMax := 0
	for i, e := 0, len(ranges)-1; i < e; i++ {
		rightClosestMinMax[ranges[i+1]] = []int{-1, -1}
		for j := ranges[i+1] - 1; j >= ranges[i]+1; j-- {

			if nums[j] == minK {
				rightMin = j
			} else {
				rightMin = rightClosestMinMax[j+1][0]
			}
			if nums[j] == maxK {
				rightMax = j
			} else {
				rightMax = rightClosestMinMax[j+1][1]
			}
			rightClosestMinMax[j] = []int{rightMin, rightMax}
		}
		for j := ranges[i] + 1; j < ranges[i+1]; j++ {
			if rightClosestMinMax[j][0] == -1 {
				continue
			}
			if rightClosestMinMax[j][1] == -1 {
				continue
			}
			largerLimit = rightClosestMinMax[j][0]
			if rightClosestMinMax[j][1] > largerLimit {
				largerLimit = rightClosestMinMax[j][1]
			}
			result += int64(ranges[i+1] - largerLimit)
		}
	}
	return result
}
