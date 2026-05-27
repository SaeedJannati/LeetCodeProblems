package LeetCode3121CountTheNumberOfSpecialCharactersII

func numberOfSpecialChars(word string) int {
	upperCase := make(map[rune]int)
	lowerCase := make(map[rune]int)
	for i, e := 0, len(word); i < e; i++ {
		if word[i] > 'Z' {
			lowerCase[rune(word[i])] = i
			continue
		}
		if _, ok := upperCase[rune(word[i])]; ok {
			continue
		}
		upperCase[rune(word[i])] = i
	}
	result := 0
	for i := 'a'; i <= 'z'; i++ {
		if _, ok := lowerCase[i]; !ok {
			continue
		}
		if _, ok := upperCase[i-'a'+'A']; !ok {
			continue
		}
		if lowerCase[i] > upperCase[i-'a'+'A'] {
			continue
		}
		result++
	}
	return result
}
