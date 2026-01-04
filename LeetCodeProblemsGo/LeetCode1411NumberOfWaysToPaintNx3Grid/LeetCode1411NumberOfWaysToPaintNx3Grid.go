package LeetCode1411NumberOfWaysToPaintNx3Grid

func numOfWays(n int) int {
	dp := make([][]int64, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int64, 2)
	}
	var mod int64 = 1e9 + 7
	// same colour begin and end-> 3 same, 2 not same
	// not same begin and end -> 2 same,  2 not same
	dp[0][0] = 6
	dp[0][1] = 6
	for i := 1; i < n; i++ {
		dp[i][0] = (3*dp[i-1][0] + 2*dp[i-1][1]) % mod
		dp[i][1] = (2*dp[i-1][0] + 2*dp[i-1][1]) % mod
	}
	return int((dp[n-1][0] + dp[n-1][1]) % mod)
}
func Calculate() {
	n := 5000
	println(numOfWays(n))
}
