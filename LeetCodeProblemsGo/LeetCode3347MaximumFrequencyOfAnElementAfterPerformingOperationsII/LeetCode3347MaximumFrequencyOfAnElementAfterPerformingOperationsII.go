package LeetCode3347MaximumFrequencyOfAnElementAfterPerformingOperationsII

import "slices"

func maxFrequency(nums []int, k int, numOperations int) int {
	slices.Sort(nums)
	frequencies := make(map[int]int)
	frequencies[nums[0]] = 1
	uniquePointer := 1
	for i, e := 1, len(nums); i < e; i++ {
		if _, exists := frequencies[nums[i]]; !exists {
			frequencies[nums[i]] = 1
			nums[i], nums[uniquePointer] = nums[uniquePointer], nums[i]
			uniquePointer++
			continue
		}
		frequencies[nums[i]]++
	}
	prefixSums := make([]int, uniquePointer)
	for i := 1; i < uniquePointer; i++ {
		prefixSums[i] = prefixSums[i-1] + frequencies[nums[i-1]]
	}
	maxFrequency := 0
	begin := 0
	end := 0
	left := 0
	right := 0
	mid := 0
	currentFrequency := 0
	for i := 0; i < uniquePointer; i++ {
		begin = 0
		end = i - 1
		left = i
		for begin <= end {
			mid = (begin + end) >> 1
			if nums[i]-nums[mid] <= k {
				end = mid - 1
				left = min(left, mid)
				continue
			}
			begin = mid + 1
		}
		begin = i + 1
		end = uniquePointer - 1
		right = i
		for begin <= end {
			mid := (begin + end) >> 1
			if nums[mid]-nums[i] <= k {
				begin = mid + 1
				right = max(right, mid)
				continue
			}
			end = mid - 1
		}
		currentFrequency = frequencies[nums[i]] + min(numOperations, prefixSums[right]-prefixSums[left]+frequencies[nums[right]]-frequencies[nums[i]])
		maxFrequency = max(maxFrequency, currentFrequency)
	}
	var lower int64
	var upper int64
	for i := 0; i < uniquePointer-1; i++ {
		lower = int64(nums[i]) + int64(k)
		begin = i
		end = uniquePointer - 1
		right = i
		for begin <= end {
			mid = (begin + end) >> 1
			upper = int64(nums[mid] - k)
			if upper <= lower {
				right = max(right, mid)
				begin = mid + 1
				continue
			}
			end = mid - 1
		}
		currentFrequency = min(numOperations, prefixSums[right]-prefixSums[i]+frequencies[nums[right]])
		maxFrequency = max(maxFrequency, currentFrequency)
	}
	return maxFrequency
}
