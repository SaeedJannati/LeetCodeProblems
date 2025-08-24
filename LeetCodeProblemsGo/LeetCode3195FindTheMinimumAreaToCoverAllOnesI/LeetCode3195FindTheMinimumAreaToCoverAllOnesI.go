package LeetCode3195FindTheMinimumAreaToCoverAllOnesI

func minimumArea(grid [][]int) int {
	heigth, width := len(grid), len(grid[0])
	minHeigth, maxHeight, minWidth, maxWidth := heigth, -1, width, -1
	for i := 0; i < heigth; i++ {
		for j := 0; j < width; j++ {
			if grid[i][j] == 0 {
				continue
			}
			if i < minHeigth {
				minHeigth = i
			}
			if i > maxHeight {
				maxHeight = i
			}
			if j < minWidth {
				minWidth = j
			}
			if j > maxWidth {
				maxWidth = j
			}
		}

	}
	return (maxHeight - minHeigth + 1) * (maxWidth - minWidth + 1)
}
