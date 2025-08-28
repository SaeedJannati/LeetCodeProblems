package LeetCode3446SortMatrixByDiagonals

import (
	"slices"
	"sort"
)

func sortMatrix(grid [][]int) [][]int {
	length := len(grid)
	nums := make([]int, 0, length)
	for i := 0; i < length; i++ {
		if i > 0 {
			nums = []int{}
			for j := 0; j < length-i; j++ {
				nums = append(nums, grid[j][i+j])
			}
			slices.Sort(nums)
			for j := 0; j < length-i; j++ {
				grid[j][i+j] = nums[j]
			}
		}
		nums = []int{}
		for j := 0; j < length-i; j++ {
			nums = append(nums, grid[j+i][j])
		}
		sort.Slice(nums, func(a, b int) bool {
			return nums[a] > nums[b]
		})
		for j := 0; j < length-i; j++ {
			grid[i+j][j] = nums[j]
		}
	}
	return grid
}
