package LeetCode1925CountSquareSumTriples

import "math"

func countTriples(n int) int {
	result := 0
	sumOfSquars := 0
	squareRoot := 0
	for i := 1; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			sumOfSquars = i*i + j*j
			squareRoot = int(math.Sqrt(float64(sumOfSquars)))
			if squareRoot <= n && squareRoot*squareRoot == sumOfSquars {
				result += 2
			}
		}
	}
	return result
}
