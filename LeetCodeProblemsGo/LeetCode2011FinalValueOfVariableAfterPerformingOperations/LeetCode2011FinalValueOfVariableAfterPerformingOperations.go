package LeetCode2011FinalValueOfVariableAfterPerformingOperations

func finalValueAfterOperations(operations []string) int {
	result := 0
	for _, operation := range operations {
		for _, r := range operation {
			if r == '+' {
				result++
				break
			}
			if r == '-' {
				result--
				break
			}
		}
	}
	return result
}
