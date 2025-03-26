package LeetCode2033MinimumOperationsToMakeAUniValueGrid

import (
	"math"
	"sort"
)

func minOperations(grid [][]int, x int) int {
	x = int(math.Abs(float64(x)))
	height := len(grid)
	width := len(grid[0])
	nums := make([]int, height*width)
	moduloX := grid[0][0] % x
	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			if grid[i][j]%x != moduloX {
				return -1
			}
			nums[i*width+j] = grid[i][j]
		}
	}
	sort.Ints(nums)
	median := nums[(height*width)/2]
	operations := 0
	for _, num := range nums {
		operations += int(math.Abs(float64(num-median))) / x
	}
	return operations
}
