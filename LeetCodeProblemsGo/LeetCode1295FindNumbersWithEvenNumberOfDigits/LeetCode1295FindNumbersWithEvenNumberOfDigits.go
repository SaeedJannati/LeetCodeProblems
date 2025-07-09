package LeetCode1295FindNumbersWithEvenNumberOfDigits

import "math"

func findNumbers(nums []int) int {
	oddCount := 0
	for _, num := range nums {
		if int(math.Ceil(math.Log10(float64(num+1))))%2 == 0 {
			oddCount++
		}
	}
	return oddCount
}
