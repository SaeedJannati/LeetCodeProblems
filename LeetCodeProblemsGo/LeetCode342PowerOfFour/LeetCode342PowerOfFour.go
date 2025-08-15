package LeetCode342PowerOfFour

func isPowerOfFour(n int) bool {
	if n <= 0 {
		return false
	}
	if (n & (n - 1)) != 0 {
		return false
	}
	if (n-1)%3 == 0 {
		return true
	}
	return false
}
