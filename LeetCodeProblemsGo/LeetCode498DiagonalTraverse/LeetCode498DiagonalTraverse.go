package LeetCode498DiagonalTraverse

func findDiagonalOrder(mat [][]int) []int {
	heigth := len(mat)
	width := len(mat[0])
	startPos := []int{0, 0}
	currentPos := []int{0, 0}
	isGoingDown := true
	result := make([]int, 0, heigth*width)
	for len(result) < heigth*width {
		currentPos[0], currentPos[1] = startPos[0], startPos[1]
		if isGoingDown {
			for currentPos[0] >= 0 && currentPos[1] < width {
				result = append(result, mat[currentPos[0]][currentPos[1]])
				currentPos[0]--
				currentPos[1]++
			}
			currentPos[0]++
			currentPos[1]--
			if currentPos[1]+1 < width {
				startPos[1] = currentPos[1] + 1
				startPos[0] = currentPos[0]
			} else {
				startPos[0] = currentPos[0] + 1
				startPos[1] = currentPos[1]
			}
		} else {
			for currentPos[1] >= 0 && currentPos[0] < heigth {
				result = append(result, mat[currentPos[0]][currentPos[1]])
				currentPos[0]++
				currentPos[1]--
			}
			currentPos[0]--
			currentPos[1]++
			if currentPos[0]+1 < heigth {
				startPos[0] = currentPos[0] + 1
				startPos[1] = currentPos[1]
			} else {
				startPos[1] = currentPos[1] + 1
				startPos[0] = currentPos[0]
			}
		}
		isGoingDown = !isGoingDown
	}
	return result
}
