package LeetCode2536IncrementSubmatricesByOne

func rangeAddQueries(n int, queries [][]int) [][]int {
	result := make([][]int, n)
	for i := 0; i < n; i++ {
		result[i] = make([]int, n)
	}
	var startRow int
	var endRow int
	var endCol int
	for _, query := range queries {
		startRow = query[0]
		endRow = query[2]
		endCol = -1
		if query[3] < n-1 {
			endCol = query[3] + 1
		}
		for i := startRow; i <= endRow; i++ {
			result[i][query[1]]++
			if endCol != -1 {
				result[i][endCol]--
			}
		}
	}
	for i := 0; i < n; i++ {
		for j := 1; j < n; j++ {
			result[i][j] += result[i][j-1]
		}
	}
	return result
}
