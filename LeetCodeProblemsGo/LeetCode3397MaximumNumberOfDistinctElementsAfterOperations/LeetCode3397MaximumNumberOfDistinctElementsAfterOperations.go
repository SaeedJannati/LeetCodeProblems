package LeetCode3397MaximumNumberOfDistinctElementsAfterOperations

import (
	"math"
	"slices"
)

func maxDistinctElements(nums []int, k int) int {
	slices.Sort(nums)
	count := 0
	previous := math.MinInt32
	current := 0
	for _, num := range nums {
		current = min(max(num-k, previous+1), num+k)
		if current > previous {
			count++
			previous = current
		}
	}
	return count
}
