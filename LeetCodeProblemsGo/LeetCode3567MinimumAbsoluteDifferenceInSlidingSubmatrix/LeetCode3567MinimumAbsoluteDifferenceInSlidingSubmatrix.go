package LeetCode3567MinimumAbsoluteDifferenceInSlidingSubmatrix

import (
	"math"
)

func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}
func minAbsDiff(grid [][]int, k int) [][]int {
	height, width := len(grid), len(grid[0])
	output := make([][]int, height-k+1)
	for i := 0; i < height-k+1; i++ {
		output[i] = make([]int, width-k+1)
	}
	for i := 0; i < height-k+1; i++ {
		for j := 0; j < width-k+1; j++ {
			minValue := math.MaxInt32
			for l := 0; l < k; l++ {
				for m := 0; m < k; m++ {
					for o := 0; o < k; o++ {
						for p := 0; p < k; p++ {
							if l == o && m == p {
								continue
							}
							if grid[i+l][j+m] == grid[i+o][j+p] {
								continue
							}

							minValue = min(minValue, abs(grid[i+l][j+m]-grid[i+o][j+p]))
						}
					}
				}
			}
			if minValue == math.MaxInt32 {
				minValue = 0
			}
			output[i][j] = minValue
		}
	}
	return output
}
