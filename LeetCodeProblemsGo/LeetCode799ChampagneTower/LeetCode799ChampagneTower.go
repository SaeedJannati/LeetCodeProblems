package LeetCode799ChampagneTower

import "fmt"

func getValue(memo [][]float64, poured float64, row, col int) float64 {
	if row == 0 {
		if col > 0 {
			return 0
		}
		return poured
	}
	if memo[row][col] != -1 {
		return memo[row][col]
	}
	var result float64 = 0
	var delta float64 = 0
	if col-1 >= 0 {
		delta = max((getValue(memo, poured, row-1, col-1)-1)/2, 0)
	}
	result += delta
	delta = max((getValue(memo, poured, row-1, col)-1)/2, 0)
	result += delta
	memo[row][col] = result
	return memo[row][col]
}
func champagneTower(poured int, query_row int, query_glass int) float64 {

	memo := make([][]float64, query_row+1)
	for i := 0; i < query_row+1; i++ {
		memo[i] = make([]float64, query_row+1)
		for j := 0; j < query_row+1; j++ {
			memo[i][j] = -1
		}
	}
	res := getValue(memo, float64(poured), query_row, query_glass)
	return min(res, 1)
}
func Calculate() {
	poured, row, col := 2, 1, 1
	fmt.Println(champagneTower(poured, row, col))
}
