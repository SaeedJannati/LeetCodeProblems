package LeetCode1317ConvertIntegerToTheSumOfTwoNoZeroIntegers

func hasZero(n int) bool {
	for n > 0 {
		if n%10 == 0 {
			return true
		}
		n /= 10
	}
	return false
}
func getNoZeroIntegers(n int) []int {
	for i, e := 1, n/2; i <= e; i++ {
		if !hasZero(i) && !hasZero(n-i) {
			return []int{i, n - i}
		}
	}
	return []int{}
}
