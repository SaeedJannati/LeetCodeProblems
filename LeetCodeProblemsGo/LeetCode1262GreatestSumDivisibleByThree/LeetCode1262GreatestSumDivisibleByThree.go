package LeetCode1262GreatestSumDivisibleByThree

import "math"

func maxSumDivThree(nums []int) int {
	previous := make([]int, 3)
	for i := 0; i < 3; i++ {
		previous[i] = math.MinInt32
	}
	previous[0] = 0
	newMod := 0
	current := make([]int, 3)
	for _, num := range nums {
		for i := 0; i < 3; i++ {
			newMod = i - num%3
			if newMod < 0 {
				newMod += 3
			}
			current[i] = max(previous[i], previous[newMod]+num)
		}
		copy(previous, current)
	}
	return previous[0]

}
