package LeetCode837New21Game

func new21Game(n int, k int, maxPts int) float64 {
	var sumWindow float64 = 0.0
	dp := make([]float64, n+1)
	for i := k; i <= n; i++ {
		dp[i] = 1.0
	}
	for i, e := k, min(n, k+maxPts-1); i <= e; i++ {
		sumWindow += dp[i]
	}
	for i := k - 1; i >= 0; i-- {
		dp[i] = sumWindow / float64(maxPts)
		sumWindow += dp[i]
		if i+maxPts <= n {
			sumWindow -= dp[i+maxPts]
		}
	}
	return dp[0]
}
