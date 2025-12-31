package LeetCode1970LastDayWhereYouCanStillCross

func latestDayToCross(row int, col int, cells [][]int) int {
	grid := make([][]bool, row)
	for i := 0; i < row; i++ {
		grid[i] = make([]bool, col)
	}
	leftParents := make([]int, row*col)
	rightParents := make([]int, row*col)
	for i, e := 0, row*col; i < e; i++ {
		leftParents[i] = i
		rightParents[i] = i
	}
	aggregated, newAggregated := 0, 0
	currentRow, currentCol := 0, 0
	newRow, newCol := 0, 0
	directions := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}}
	for index, cell := range cells {
		grid[cell[0]-1][cell[1]-1] = true
		currentRow, currentCol = cell[0]-1, cell[1]-1
		aggregated = currentRow*col + currentCol
		for _, dir := range directions {
			newRow, newCol = currentRow+dir[0], currentCol+dir[1]
			if newRow < 0 || newRow >= row {
				continue
			}
			if newCol < 0 || newCol >= col {
				continue
			}
			if !grid[newRow][newCol] {
				continue
			}

			newAggregated = newRow*col + newCol
			leftUnion(leftParents, col, aggregated, newAggregated)
			rightUnion(rightParents, col, aggregated, newAggregated)
			leftParent, rightParent := find(leftParents, aggregated), find(rightParents, aggregated)
			if leftParent%col == 0 && rightParent%col == col-1 {
				return index
			}
		}
	}
	return len(cells)
}
func find(parents []int, item int) int {
	if parents[item] != item {
		parents[item] = find(parents, parents[item])
	}
	return parents[item]
}
func rightUnion(parents []int, col, first, second int) {
	firstParent := find(parents, first)
	secondParent := find(parents, second)
	if firstParent%col > secondParent%col {
		parents[secondParent] = firstParent
		return
	}
	parents[firstParent] = secondParent
}

func leftUnion(parents []int, col, first, second int) {
	firstParent := find(parents, first)
	secondParent := find(parents, second)
	if firstParent%col < secondParent%col {
		parents[secondParent] = firstParent
		return
	}
	parents[firstParent] = secondParent
}

func Calculate() {
	row :=
		2
		// 3
	col :=
		2
		// 3
	cells :=
		[][]int{{1, 1}, {2, 1}, {1, 2}, {2, 2}}
		// [][]int{{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}, {1, 3}, {2, 3}, {3, 2}, {3, 1}}
	println(latestDayToCross(row, col, cells))
}
