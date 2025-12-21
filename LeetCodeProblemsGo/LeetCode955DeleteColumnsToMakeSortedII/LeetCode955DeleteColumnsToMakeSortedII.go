package LeetCode955DeleteColumnsToMakeSortedII

func minDeletionSize(strs []string) int {
	height := len(strs)
	width := len(strs[0])
	columnsToDelete := 0
	rowsToCheck := make(map[int]any)
	for i := 0; i < height-1; i++ {
		rowsToCheck[i] = nil
	}
	colDeleted := false
	newRowsToCheck := make(map[int]any)
	for col := 0; col < width; col++ {
		colDeleted = false
		newRowsToCheck = make(map[int]any)
		for key, _ := range rowsToCheck {
			newRowsToCheck[key] = nil
		}
		for row := 0; row < height-1; row++ {

			if _, exists := rowsToCheck[row]; !exists {
				continue
			}
			if strs[row][col] > strs[row+1][col] {
				columnsToDelete++
				colDeleted = true
				break
			}
			if strs[row][col] < strs[row+1][col] {
				delete(newRowsToCheck, row)
			}
		}
		if !colDeleted {
			rowsToCheck = make(map[int]any)
			for key, _ := range newRowsToCheck {
				rowsToCheck[key] = nil
			}
		}
	}
	return columnsToDelete
}
func Calculate() {
	strs := []string{"vdy", "vei", "zvc", "zld"}
	result := minDeletionSize(strs)
	println(result)
}
