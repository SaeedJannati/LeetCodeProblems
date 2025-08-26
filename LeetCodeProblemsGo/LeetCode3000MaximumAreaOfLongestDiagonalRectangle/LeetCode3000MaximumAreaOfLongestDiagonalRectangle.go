package LeetCode3000MaximumAreaOfLongestDiagonalRectangle

func areaOfMaxDiagonal(dimensions [][]int) int {
	maxDiagonal := 0
	diagonal := 0
	area := 0
	maxArea := 0
	for _, dimension := range dimensions {
		diagonal = dimension[0]*dimension[0] + dimension[1]*dimension[1]
		if diagonal == maxDiagonal {
			area = dimension[0] * dimension[1]
			maxArea = max(area, maxArea)
			continue
		}
		if diagonal > maxDiagonal {
			maxDiagonal = diagonal
			maxArea = dimension[0] * dimension[1]
		}
	}
	return maxArea
}
