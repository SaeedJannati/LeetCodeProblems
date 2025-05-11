package main

func minSum(nums1 []int, nums2 []int) int64 {
	firstZeroCount := 0
	var firstSum int64 = 0
	firstLength := len(nums1)
	secondZeroCount := 0
	var secondSum int64 = 0
	secondLength := len(nums2)
	for i := 0; i < firstLength; i++ {
		if nums1[i] == 0 {
			firstZeroCount++
			continue
		}
		firstSum += int64(nums1[i])
	}
	for i := 0; i < secondLength; i++ {
		if nums2[i] == 0 {
			secondZeroCount++
			continue
		}
		secondSum += int64(nums2[i])
	}
	firstSum += int64(firstZeroCount)
	secondSum += int64(secondZeroCount)
	if firstZeroCount == 0 {
		if firstSum < secondSum {
			return -1
		}
	}
	if secondZeroCount == 0 {
		if secondSum < firstSum {
			return -1
		}
	}
	if firstSum < secondSum {
		return secondSum
	}
	return firstSum
}
