package LeetCode3228MaximumNumberOfOperationsToMoveOnesToTheEnd

func maxOperations(s string) int {
	length := len(s)
	oneCount := 0
	moveCount := 0
	for i := 0; i < length; i++ {
		if s[i] == '1' {
			oneCount++
			continue
		}
		if i > 0 && s[i] == '0' && s[i-1] == '1' {
			moveCount += oneCount
		}
	}
	return moveCount
}
