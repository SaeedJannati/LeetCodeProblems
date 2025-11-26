package LeetCode2435PathsInMatrixWhoseSumIsDivisibleByK

func numberOfPaths(grid [][]int, k int) int {
	mod := 1e9 + 7
	heigth := len(grid)
	width := len(grid[0])
	dp := make([][][]int64, heigth)
	for i := 0; i < heigth; i++ {
		dp[i] = make([][]int64, width)
		for j := 0; j < width; j++ {
			dp[i][j] = make([]int64, k)
		}
	}
	dp[0][0][grid[0][0]%k] = 1
	newMod := 0
	for i := 0; i < heigth; i++ {
		for j := 0; j < width; j++ {
			if i == 0 && j == 0 {
				continue
			}
			for r := 0; r < k; r++ {
				newMod = r - grid[i][j]%k
				if newMod < 0 {
					newMod += k
				}
				if i > 0 {
					dp[i][j][r] += dp[i-1][j][newMod]
				}
				if j > 0 {
					dp[i][j][r] += dp[i][j-1][newMod]
				}
				dp[i][j][r] %= int64(mod)
			}
		}
	}
	return int(dp[heigth-1][width-1][0])
}
