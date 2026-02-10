package LeetCode3719LongestBalancedSubarrayI

import "fmt"

func longestBalanced(nums []int) int {
	length := len(nums)

	maxLength := 0
	for i := 0; i < length; i++ {
		evens := make(map[int]any)
		odds := make(map[int]any)

		for j := i; j < length; j++ {
			if nums[j]%2 == 0 {
				evens[nums[j]] = struct{}{}
			} else {
				odds[nums[j]] = struct{}{}
			}
			if len(odds) == len(evens) {
				maxLength = max(maxLength, j-i+1)
			}
		}
	}
	return maxLength
}
func Calculate() {
	nums := []int{10, 6, 10, 7}
	fmt.Println(longestBalanced(nums))
}
