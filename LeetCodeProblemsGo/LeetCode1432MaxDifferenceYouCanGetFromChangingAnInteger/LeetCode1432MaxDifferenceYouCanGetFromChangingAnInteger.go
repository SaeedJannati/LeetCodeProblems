package LeetCode1432MaxDifferenceYouCanGetFromChangingAnInteger

func getDigits(num int) []int {
	result := []int{}
	for num > 0 {
		result = append(result, num%10)
		num /= 10
	}
	return result
}
func maxDiff(num int) int {
	digits := getDigits(num)
	length := len(digits)
	digitToChange := -1
	for i := length - 1; i >= 0; i-- {
		if digits[i] != 9 {
			digitToChange = digits[i]
			break
		}
	}
	maxNum := num
	if digitToChange != -1 {
		maxNum = 0
		for i := length - 1; i >= 0; i-- {
			maxNum *= 10
			if digits[i] == digitToChange {
				maxNum += 9
			} else {
				maxNum += digits[i]
			}
		}
	}
	digitToChange = -1
	digitToReplace := 0
	firstDigit := digits[length-1]
	if firstDigit != 1 {
		digitToChange = firstDigit
		digitToReplace = 1
	} else {
		for i := length - 2; i >= 0; i-- {
			if digits[i] == 0 {
				continue
			}
			if digits[i] == firstDigit {
				continue
			}
			digitToChange = digits[i]
			digitToReplace = 0
			break
		}
	}
	minNum := num
	if digitToChange != -1 {
		minNum = 0
		for i := length - 1; i >= 0; i-- {
			minNum *= 10
			if digits[i] == digitToChange {
				minNum += digitToReplace
			} else {
				minNum += digits[i]
			}
		}
	}
	return maxNum - minNum
}
