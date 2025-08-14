package LeetCode2264Largest3SameDigitNumberInString

func largestGoodInteger(num string) string {
	result := ""

	largestFound := '0' - 1
	lastDigit := '0'
	occurance := 0
	for _, char := range num {
		if char < largestFound {
			lastDigit = '0' - 1
			continue
		}
		if char != lastDigit {
			occurance = 1
			lastDigit = char
			continue
		}
		occurance++
		if occurance == 3 {
			if lastDigit > largestFound {
				largestFound = lastDigit
			}
			if lastDigit == '9' {
				break
			}
		}
	}
	if largestFound < '0' {
		return ""
	}
	result = string(largestFound)
	result = result + result + result
	return result
}
