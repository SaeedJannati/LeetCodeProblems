package LeetCode3074AppleRedistributionIntoBoxes

import (
	"sort"
)

func minimumBoxes(apple []int, capacity []int) int {
	sort.Slice(capacity, func(a, b int) bool {
		return capacity[a] > capacity[b]
	})
	length := len(capacity)
	applesCount := 0
	for _, apple := range apple {
		applesCount += apple
	}
	result := 0
	currentSum := 0
	for i := 0; i < length; i++ {
		currentSum += capacity[i]
		result++
		if currentSum >= applesCount {
			return result
		}
	}
	return result
}
