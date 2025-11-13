package LeetCode474OnesAndZeroes

func findMaxForm(strs []string, m int, n int) int {
	length := len(strs)
	zerosAndOnes := make([][]int, length)
	var zeroCount int
	var oneCount int
	for i := 0; i < length; i++ {
		zeroCount = 0
		oneCount = 0
		for _, c := range strs[i] {
			if c == '0' {
				zeroCount++
				continue
			}
			oneCount++
		}
		zerosAndOnes[i] = []int{zeroCount, oneCount}
	}
	dp := make([][][]int, m+1)
	for i := 0; i < m+1; i++ {
		dp[i] = make([][]int, n+1)
		for j := 0; j < n+1; j++ {
			dp[i][j] = make([]int, 2)
		}
	}
	maxNum := 0
	current := 0
	previous := 1
	for i := 0; i < length; i++ {
		for j := 0; j < m+1; j++ {
			for k := 0; k < n+1; k++ {
				if zerosAndOnes[i][0] > j || zerosAndOnes[i][1] > k {
					if i > 0 {
						dp[j][k][current] = dp[j][k][previous]
					}
					continue
				}
				if i == 0 {
					dp[j][k][current] = 1
					maxNum = max(maxNum, dp[j][k][current])
					continue
				}
				dp[j][k][current] = max(dp[j][k][previous], dp[j-zerosAndOnes[i][0]][k-zerosAndOnes[i][1]][previous]+1)
				maxNum = max(maxNum, dp[j][k][current])
			}
		}
		current ^= previous
		previous ^= current
		current ^= previous
	}
	return maxNum
}
