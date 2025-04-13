package LeetCode1922CountGoodNumbers

var mod int64 = 1000000007

func countGoodNumbers(n int64) int {
	var powFour int64 = n / 2
	var powFive int64 = n - (n)/2
	result := pow(4, powFour)
	result %= mod
	result *= pow(5, powFive)
	result %= mod
	return int(result)
}

func pow(a int64, b int64) int64 {
	var power int64 = 1
	var current int64 = a
	var result int64 = 1
	for power <= b {
		if (power & b) != 0 {
			result *= current
			result %= mod
		}
		current *= current
		current %= mod
		power <<= 1
	}
	return result
}
