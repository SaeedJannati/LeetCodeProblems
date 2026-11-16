package LeetCode2243CalculateDigitSumOfAString

import "strconv"

func digitSum(s string, k int) string {
	length := len(s)
	if length <= k {
		return s
	}
	i, j := 0, 0
	outPut := ""
	for i*k+j < length {
		current := ""
		for j := 0; j < k; j++ {
			if i*k+j >= length {
				break
			}
			current += string(s[i*k+j])
		}
		outPut += calcPart(current)
		i++
	}
	return digitSum(outPut, k)
}
func calcPart(s string) string {
	sum := 0
	for _, c := range s {
		sum += int(c - '0')

	}
	return strconv.Itoa(sum)
}
