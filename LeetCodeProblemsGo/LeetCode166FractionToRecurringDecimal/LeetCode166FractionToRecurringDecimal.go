package LeetCode166FractionToRecurringDecimal

import (
	"fmt"
	"strconv"
)

func fractionToDecimal(numerator int, denominator int) string {
	if numerator == 0 {
		return "0"
	}
	result := []byte{}
	var num int64 = int64(numerator)
	var den int64 = int64(denominator)
	if num%den == 0 {
		return strconv.FormatInt(num/den, 10)
	}
	if (num < 0) != (den < 0) {
		result = append(result, '-')
	}
	if num < 0 {
		num = -num
	}
	if den < 0 {
		den = -den
	}
	mapIndex := make(map[int64]int)
	addedDot := false
	for {
		delta := num / den
		newNum := num % den
		if newNum == 0 {
			result = append(result, []byte(strconv.Itoa(int(delta)))...)
			break
		}
		if _, exists := mapIndex[num]; !exists {
			if addedDot {
				mapIndex[num] = len(result)
			}
			result = append(result, []byte(strconv.Itoa(int(delta)))...)
			num = newNum * 10
			if !addedDot {
				result = append(result, '.')
				addedDot = true
			}
			continue
		}
		start := mapIndex[num]
		repeatingPart := make([]byte, len(result[start:]))
		copy(repeatingPart, result[start:])
		result = result[:mapIndex[num]]
		result = append(result, '(')
		result = append(result, repeatingPart...)
		result = append(result, ')')
		break
	}
	return string(result)
}
func Calculate() {
	num := 4
	den := 333
	fmt.Println(fractionToDecimal(num, den))
}
