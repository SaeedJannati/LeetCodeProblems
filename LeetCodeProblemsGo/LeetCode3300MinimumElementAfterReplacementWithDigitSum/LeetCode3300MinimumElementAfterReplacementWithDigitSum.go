package LeetCode3300MinimumElementAfterReplacementWithDigitSum

import "math"

func minElement(nums []int) int {
	minDigitSum := math.MaxInt32
	for _, num := range nums {
		minDigitSum = min(minDigitSum, getDigitSum(num))
	}
	return minDigitSum
}
func getDigitSum(num int) int {
	sum := 0
	for num > 0 {
		sum += num % 10
		num /= 10
	}
	return sum
}
