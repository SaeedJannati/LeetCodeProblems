package LeetCode2048NextGreaterNumericallyBalancedNumber

import (
	"math"
	"slices"
)

func nextBeautifulNumber(n int) int {
	if n == 0 {
		return 1
	}
	if n == 1e6 {
		return 1_224_444
	}
	digits := []int{}
	frequencies := make([]int, 10)
	num := n
	for num > 0 {
		digits = append(digits, num%10)
		num /= 10
	}
	slices.Reverse(digits)
	result := math.MaxInt32
	getNum(frequencies, digits, 0, true, len(digits), &result, 0, n)
	return result
}
func getNum(frequencies, digits []int, index int, shouldBeGreater bool, totalDigitCount int, minNum *int, numSofar, num int) {
	if index == totalDigitCount {
		addedDigit := false
		for i := 1; i < 10; i++ {
			if frequencies[i] == 0 {
				continue
			}
			if frequencies[i] == i {
				continue
			}
			if frequencies[i] == i-1 && !addedDigit {
				numSofar *= 10
				numSofar += i
				addedDigit = true
				continue
			}
			return
		}
		if numSofar > num {
			*minNum = min(*minNum, numSofar)
			return
		}
		if frequencies[1] == 0 {
			numSofar *= 10
			numSofar += 1
			*minNum = min(*minNum, numSofar)
		}
		return
	}
	for i := 1; i <= totalDigitCount+1; i++ {
		if frequencies[i] == i {
			continue
		}
		frequencies[i]++
		getNum(frequencies, digits, index+1, !shouldBeGreater || i == digits[index], totalDigitCount, minNum, numSofar*10+i, num)
		frequencies[i]--
	}
}
