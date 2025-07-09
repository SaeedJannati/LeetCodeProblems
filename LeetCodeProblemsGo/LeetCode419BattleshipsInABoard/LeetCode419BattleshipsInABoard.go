package LeetCode419BattleshipsInABoard

func countBattleships(board [][]byte) int {
	directions := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	shipCount := 0
	height := len(board)
	width := len(board[0])
	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			if board[i][j] == '0' {
				continue
			}
			if board[i][j] == '.' {
				board[i][j] = '0'
				continue
			}
			if board[i][j] == 'X' {
				shipCount++
				board[i][j] = '0'
				dfs(board, directions, height, width, i, j)
			}
		}
	}
	return shipCount
}
func dfs(board [][]byte, directions [][]int, height, width, row, col int) {
	newRow := 0
	newCol := 0
	for _, direction := range directions {
		newRow = row + direction[0]
		if newRow < 0 || newRow >= height {
			continue
		}
		newCol = col + direction[1]
		if newCol < 0 || newCol >= width {
			continue
		}
		if board[newRow][newCol] != 'X' {
			continue
		}
		board[newRow][newCol] = '0'
		dfs(board, directions, height, width, newRow, newCol)
	}
}
