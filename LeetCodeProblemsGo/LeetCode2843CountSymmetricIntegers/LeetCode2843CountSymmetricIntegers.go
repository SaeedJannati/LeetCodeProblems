package LeetCode2843CountSymmetricIntegers

import "math"

func countSymmetricIntegers(low int, high int) int {
	digitCount := 0
	result := 0
	num := 0
	digitSum := 0
	digit := 0
	counter := 0
	for i := low; i <= high; i++ {
		digitCount = int(math.Log10(float64(i))) + 1
		if digitCount%2 != 0 {
			i = int(math.Pow10(digitCount))
			continue
		}
		counter = digitCount / 2
		num = i
		digitSum = 0
		for num > 0 {
			digit = num % 10
			num /= 10
			if counter > 0 {
				digitSum += digit
			} else {
				digitSum -= digit
			}
			counter--
		}
		if digitSum == 0 {
			result++
		}
	}
	return result
}
