package LeetCode2110NumberOfSmoothDescentPeriodsOfAStock

func getDescentPeriods(prices []int) int64 {
	length := len(prices)
	dp := make([]int, length)
	dp[0] = 1
	for i := 1; i < length; i++ {
		if prices[i-1]-prices[i] == 1 {
			dp[i] = dp[i-1] + 1
			continue
		}
		dp[i] = 1
	}
	var result int64 = 0
	var delta int64 = 0
	for i := length - 1; i >= 0; {
		if dp[i] > 1 {
			delta = int64(dp[i] + 1)
			delta *= delta - 1
			delta >>= 1
			result += delta
			i -= dp[i]
			continue
		}
		result += int64(dp[i])
		i--
	}
	return result
}
