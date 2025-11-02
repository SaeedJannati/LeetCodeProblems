package LeetCode2257CountUnguardedCellsInTheGrid

func countUnguarded(m int, n int, guards [][]int, walls [][]int) int {

	// 1 wall
	//2 guard
	// 3 supervised
	grid := make([][]int, m)
	for i := 0; i < m; i++ {
		grid[i] = make([]int, n)
	}
	for _, wall := range walls {
		grid[wall[0]][wall[1]] = 1
	}
	for _, guard := range guards {
		grid[guard[0]][guard[1]] = 2
	}
	directions := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	newRow := 0
	newCol := 0
	for _, guard := range guards {
		for _, direction := range directions {
			newRow = guard[0]
			newCol = guard[1]
			for true {
				newRow += direction[0]
				if newRow < 0 || newRow >= m {
					break
				}
				newCol += direction[1]
				if newCol < 0 || newCol >= n {
					break
				}
				if grid[newRow][newCol] == 1 || grid[newRow][newCol] == 2 {
					break
				}
				grid[newRow][newCol] = 3
			}
		}
	}
	result := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 {
				result++
			}
		}
	}
	return result
}
