package LeetCode3751TotalWavinessOfNumbersInRangeI

func totalWaviness(num1 int, num2 int) int {
	result := 0
	for ; num1 <= num2; num1++ {
		result += getWaviness(num1)
	}
	return result
}

func getWaviness(num int) int {
	previous := num % 10
	num /= 10
	next, result, current := 0, 0, 0
	for num > 0 {
		current = num % 10
		num /= 10
		if num == 0 {
			return result
		}
		next = num % 10
		if (current > previous && current > next) || (current < previous && current < next) {
			result++
		}
		previous = current
	}
	return result
}
