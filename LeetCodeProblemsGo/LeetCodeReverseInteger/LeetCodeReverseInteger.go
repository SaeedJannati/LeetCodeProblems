package LeetCodeReverseInteger

import (
	"math"
)

func reverse(x int) int {
	if x == math.MinInt32 {
		return 0
	}
	isPos := x >= 0
	if !isPos {
		x = -x
	}
	digits := []int{}
	for x > 0 {
		digits = append(digits, x%10)
		x /= 10
	}
	result := 0
	for _, digit := range digits {
		if result > (math.MaxInt32-digit)/10 {
			return 0
		}
		result = result*10 + digit
	}
	if !isPos {
		result = -result
	}
	return result
}
