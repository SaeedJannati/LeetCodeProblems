package LeetCode3403FindTheLexicographicallyLargestStringFromTheBoxI

func answerString(word string, numFriends int) string {
	if numFriends == 1 {
		return word
	}
	length := len(word)
	maxLength := length - numFriends + 1
	answer := word[0:maxLength]
	var candidate string
	var possibleLength int
	for i := 1; i < length; i++ {
		possibleLength = maxLength
		if i+maxLength >= length {
			possibleLength = length - maxLength
		}
		candidate = word[i : i+possibleLength]
		if !isLexicographicallyLarger(answer, candidate) {
			continue
		}
		answer = candidate
	}
	return answer
}
func isLexicographicallyLarger(source string, candidate string) bool {
	sourceLength := len(source)
	candidateLength := len(candidate)
	counter := 0
	for counter < sourceLength || counter < candidateLength {
		if counter < sourceLength && counter < candidateLength {
			if source[counter] == candidate[counter] {
				counter++
				continue
			}
			return source[counter] < candidate[counter]
		}
		if counter < candidateLength {
			return true
		}
		return false
	}
	return false
}
