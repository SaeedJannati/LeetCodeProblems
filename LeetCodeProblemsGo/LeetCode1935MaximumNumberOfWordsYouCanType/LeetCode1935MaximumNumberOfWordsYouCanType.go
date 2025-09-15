package LeetCode1935MaximumNumberOfWordsYouCanType

func canBeTypedWords(text string, brokenLetters string) int {
	letters := make(map[byte]struct{}, len(brokenLetters))
	for _, c := range brokenLetters {
		letters[byte(c)] = struct{}{}
	}
	count := 0
	hasBrokenLetter := false
	currentLength := 0
	for _, c := range text {
		if c == ' ' {
			if !hasBrokenLetter && currentLength > 0 {
				count++
				continue
			}
			currentLength = 0
			hasBrokenLetter = false
			continue
		}
		currentLength++
		if _, exists := letters[byte(c)]; exists {
			hasBrokenLetter = true
		}
	}
	if !hasBrokenLetter && currentLength > 0 {
		count++
	}
	return count
}
