package LeetCode368LargestDivisibleSubset

import (
	"fmt"
	"sort"
)

func Calculate(nums []int) {
	answer := largestDivisableSubset(nums)
	fmt.Printf("%+v \n", answer)
}
func largestDivisableSubset(nums []int) []int {
	length := len(nums)
	if length == 1 {
		return nums
	}
	sort.Ints(nums)
	dp := make(map[int][]int)
	for _, num := range nums {
		dp[num] = []int{num}
	}
	maxLength := 1
	maxIndex := nums[0]
	for i := 0; i < length; i++ {
		for j := 0; j < i; j++ {
			if nums[i]%nums[j] == 0 {
				if len(dp[nums[i]]) < len(dp[nums[j]])+1 {
					dp[nums[i]] = append([]int{}, dp[nums[j]]...)
					dp[nums[i]] = append(dp[nums[i]], nums[i])
					if len(dp[nums[i]]) > maxLength {
						maxLength = len(dp[nums[i]])
						maxIndex = nums[i]
					}
				}
			}
		}
	}
	return dp[maxIndex]
}
