package LeetCode326PowerOfThree

func isPowerOfThree(n int) bool {
	if n <= 0 {
		return false
	}
	return isDvisiable(n, 3)
}
func isDvisiable(n, pow int) bool {
	if n == 1 {
		return true
	}
	if pow > n {
		pow = 3
		if isDvisiable(n, 3) {
			return true
		}
	}
	if n%pow == 0 {
		return isDvisiable(n/pow, pow*pow)
	}
	return false
}
