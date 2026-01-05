package LeetCode1975MaximumMatrixSum

import "math"

func maxMatrixSum(matrix [][]int) int64 {
	var maxSum int64
	minAbsolute := math.MaxInt32
	negativeCount := 0
	for _, row := range matrix {
		for _, num := range row {
			if num < 0 {
				negativeCount++
				num *= -1
			}
			maxSum += int64(num)
			minAbsolute = min(minAbsolute, num)
		}
	}
	if negativeCount%2 == 1 {
		maxSum -= 2 * int64(minAbsolute)
	}
	return maxSum
}

func Calculate() {
	matrix := [][]int{{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}}
	println(maxMatrixSum(matrix))
}
