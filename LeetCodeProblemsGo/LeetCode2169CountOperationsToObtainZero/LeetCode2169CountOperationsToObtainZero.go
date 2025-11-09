package LeetCode2169CountOperationsToObtainZero

func countOperations(num1 int, num2 int) int {
	counter := 0
	for num1 != 0 && num2 != 0 {
		if num1 >= num2 {
			num1 -= num2
		} else {
			num2 -= num1
		}
		counter++
	}
	return counter
}
