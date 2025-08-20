package LeetCode1277CountSquareSubmatricesWithAllOnes

func countSquares(matrix [][]int) int {
	height := len(matrix)
	width := len(matrix[0])
	result := 0
	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			if matrix[i][j] == 0 {
				continue
			}
			if i > 0 && j > 0 {
				matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1])) + 1
			}
			result += matrix[i][j]
		}
	}
	return result
}
