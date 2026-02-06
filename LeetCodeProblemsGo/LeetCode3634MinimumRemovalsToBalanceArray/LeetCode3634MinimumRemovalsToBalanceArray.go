package LeetCode3634MinimumRemovalsToBalanceArray

import (
	"fmt"
	"slices"
)

func minRemoval(nums []int, k int) int {
	slices.Sort(nums)
	length := len(nums)
	maxLength := 0
	currentLength := 0
	begin, end, mid, found := 0, 0, 0, 0
	for i := 0; i < length; i++ {
		begin = i
		end = length - 1
		found = -1
		for begin <= end {
			mid = (begin + end) >> 1
			if nums[mid] <= k*nums[i] {
				found = max(found, mid)
				begin = mid + 1
				continue
			}
			end = mid - 1

		}
		currentLength = found - i + 1
		maxLength = max(currentLength, maxLength)
	}
	return length - maxLength
}
func Calculate() {
	nums := []int{1, 34, 23}
	k := 2
	fmt.Println(minRemoval(nums, k))
}
