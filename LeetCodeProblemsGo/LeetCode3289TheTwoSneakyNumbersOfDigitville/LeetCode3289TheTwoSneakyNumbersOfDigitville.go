package LeetCode3289TheTwoSneakyNumbersOfDigitville

func getSneakyNumbers(nums []int) []int {
	length := len(nums) - 2
	numsXor := 0
	for i := 1; i < length; i++ {
		numsXor ^= i
	}
	for _, num := range nums {
		numsXor ^= num
	}
	lowestOneBit := numsXor & -numsXor
	firstNumSet := 0
	for i := 1; i < length; i++ {
		if i&lowestOneBit != 0 {
			firstNumSet ^= i
		}
	}
	firstNum := 0
	for _, num := range nums {
		if num&lowestOneBit != 0 {
			firstNum ^= num
		}
	}
	firstNum = firstNum ^ firstNumSet
	secondNum := firstNum ^ numsXor
	return []int{firstNum, secondNum}
}
