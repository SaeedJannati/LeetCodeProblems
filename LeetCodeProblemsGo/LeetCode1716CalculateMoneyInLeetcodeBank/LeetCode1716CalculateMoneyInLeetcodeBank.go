package LeetCode1716CalculateMoneyInLeetcodeBank

func totalMoney(n int) int {
	res := n/7*28 + (n/7-1)*(n/7)*7/2 + (n%7)*((n%7)+1)/2
	if n/7 > 0 {
		res += (n % 7) * (n / 7)
	}
	return res
}
