package LeetCode2749MinimumOperationsToMakeTheIntegerZero

func getDigitCount(num int64) int {
	result := 0
	for i := 0; i < 64; i++ {
		if (num & 1) == 1 {
			result++
		}
		num >>= 1
		if num == 0 {
			return result
		}
	}
	return result
}
func makeTheIntegerZero(num1 int, num2 int) int {
	for i := 1; i <= 60; i++ {
		var x int64 = int64(num1) - int64(num2)*int64(i)
		if x < int64(i) {
			continue
		}
		if getDigitCount(x) <= i {
			return i
		}
	}
	return -1
}
