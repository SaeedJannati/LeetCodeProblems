package LeetCode2563CountTheNumberOfFairPairs

import "slices"

func countFairPairs(nums []int, lower int, upper int) int64 {
	var output int64 = 0
	slices.Sort(nums)
	length := len(nums)
	min := 0
	max := 0
	for i := 0; i < length-1; i++ {
		min = getMinIndex(nums, i, length, lower)
		if min == length {
			continue
		}
		max = getMaxIndex(nums, i, length, upper)
		if max == 0 {
			continue
		}
		output += int64(max - min + 1)
	}
	return output

}

func getMinIndex(nums []int, index int, length int, lower int) int {
	begin := index + 1
	end := length - 1
	var mid int
	result := length
	for begin <= end {
		mid = (begin + end) / 2
		if nums[mid]+nums[index] < lower {
			begin = mid + 1
			continue
		}
		if mid < result {
			result = mid
		}
		end = mid - 1
	}
	return result
}

func getMaxIndex(nums []int, index int, length int, upper int) int {
	begin := index + 1
	end := length - 1
	var mid int
	result := 0
	for begin <= end {
		mid = (begin + end) / 2
		if nums[mid]+nums[index] > upper {
			end = mid - 1
			continue
		}
		result = max(result, mid)
		begin = mid + 1
	}
	return result
}
