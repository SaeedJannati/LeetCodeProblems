package LeetCodePalindromeNumber

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	digits := []int{}
	for x > 0 {
		digits = append(digits, x%10)
		x = x / 10
	}
	n := len(digits)
	for i := 0; i < n/2; i++ {
		if digits[i] != digits[n-1-i] {
			return false
		}
	}
	return true
}
