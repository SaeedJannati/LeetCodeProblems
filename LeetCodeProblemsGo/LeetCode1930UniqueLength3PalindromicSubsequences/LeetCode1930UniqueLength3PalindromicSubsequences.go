package LeetCode1930UniqueLength3PalindromicSubsequences

func countPalindromicSubsequence(s string) int {
	countedPalindromes := make(map[int]any)
	length := len(s)
	prefixLetters := make([]int, length)
	suffixLetters := make([]int, length)
	for i := 1; i < length; i++ {
		prefixLetters[i] = prefixLetters[i-1] | (1 << (s[i-1] - 'a'))
	}
	for i := length - 2; i >= 0; i-- {
		suffixLetters[i] = suffixLetters[i+1] | (1 << (s[i+1] - 'a'))
	}
	overlaps := 0
	for i := 1; i < length-1; i++ {
		overlaps = prefixLetters[i] & suffixLetters[i]
		if overlaps == 0 {
			continue
		}
		for j := 0; j < 26; j++ {
			if overlaps&(1<<j) > 0 {
				palindromHash := int(s[i]-'a')*100 + j
				if _, exists := countedPalindromes[palindromHash]; !exists {
					countedPalindromes[palindromHash] = nil
				}
			}
		}
	}
	return len(countedPalindromes)
}
