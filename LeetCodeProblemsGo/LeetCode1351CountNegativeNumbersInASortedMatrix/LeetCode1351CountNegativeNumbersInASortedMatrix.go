package LeetCode1351CountNegativeNumbersInASortedMatrix

func countNegatives(grid [][]int) int {
	height := len(grid)
	width := len(grid[0])
	negativeCount := 0
	begin := 0
	end := width - 1
	mid := 0
	currentEnd := end
	result := 0
	for i := 0; i < height; i++ {
		end = currentEnd
		begin = 0
		result = end + 1
		for begin <= end {
			mid = (begin + end) >> 1
			if grid[i][mid] < 0 {
				result = min(result, mid)
				end = mid - 1
				continue
			}
			begin = mid + 1
		}
		if result == currentEnd+1 {
			continue
		}
		negativeCount += (currentEnd - result + 1) * (height - i)
		currentEnd = result - 1
	}
	return negativeCount
}
func Calculate() {
	grid := [][]int{{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}}
	println(countNegatives(grid))
}
