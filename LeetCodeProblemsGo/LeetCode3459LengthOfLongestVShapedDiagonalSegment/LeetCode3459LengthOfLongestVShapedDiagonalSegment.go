package LeetCode3459LengthOfLongestVShapedDiagonalSegment

func lenOfVDiagonal(grid [][]int) int {
	height, width := len(grid), len(grid[0])
	directions := [][]int{{-1, -1}, {-1, 1}, {1, 1}, {1, -1}}
	memoisation := make([][][][]int, height)
	for i := 0; i < height; i++ {
		memoisation[i] = make([][][]int, width)
		for j := 0; j < width; j++ {
			memoisation[i][j] = make([][]int, 4)
			for k := 0; k < 4; k++ {
				memoisation[i][j][k] = make([]int, 2)
			}
		}
	}
	maxLength := 0
	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			if grid[i][j] != 1 {
				continue
			}
			if maxLength == 0 {
				maxLength = 1
			}
			for k := 0; k < 4; k++ {
				maxLength = max(maxLength, getMaxLength(grid, directions, memoisation, height, width, i, j, k, 0))
			}
		}
	}
	return maxLength
}
func getNextDirection(direction int) int {
	if direction < 3 {
		return direction + 1
	}
	return 0
}
func getDesiredValue(value int) int {
	if value == 2 {
		return 0
	}
	return 2
}
func getMaxLength(grid, directions [][]int, memoisation [][][][]int, height, width, row, col, direction, hasTurned int) int {
	if memoisation[row][col][direction][hasTurned] > 0 {
		return memoisation[row][col][direction][hasTurned]
	}
	result := 1
	desiredValue := getDesiredValue(grid[row][col])
	newRow := row + directions[direction][0]
	newColumn := col + directions[direction][1]
	if newRow >= 0 && newRow < height && newColumn >= 0 && newColumn < width {
		if grid[newRow][newColumn] == desiredValue {
			result += getMaxLength(grid, directions, memoisation, height, width, newRow, newColumn, direction, hasTurned)
		}
	}
	if hasTurned == 1 {
		memoisation[row][col][direction][hasTurned] = result
		return memoisation[row][col][direction][hasTurned]
	}
	newDirection := getNextDirection(direction)
	newRow = row + directions[direction][0]
	newResult := 0
	newColumn = col + directions[direction][1]
	if newRow >= 0 && newRow < height && newColumn >= 0 && newColumn < width {
		if grid[newRow][newColumn] == desiredValue {
			newResult = 1 + getMaxLength(grid, directions, memoisation, height, width, newRow, newColumn, newDirection, 1)
			result = max(result, newResult)
		}
	}
	memoisation[row][col][direction][hasTurned] = result
	return memoisation[row][col][direction][hasTurned]
}
