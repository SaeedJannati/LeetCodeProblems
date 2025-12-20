package LeetCode944DeleteColumnsToMakeSorted

func minDeletionSize(strs []string) int {
	colsToDelete := 0
	height := len(strs)
	width := len(strs[0])
	for col := 0; col < width; col++ {
		for row := 1; row < height; row++ {
			if strs[row][col] < strs[row-1][col] {
				colsToDelete++
				break
			}
		}
	}
	return colsToDelete
}
