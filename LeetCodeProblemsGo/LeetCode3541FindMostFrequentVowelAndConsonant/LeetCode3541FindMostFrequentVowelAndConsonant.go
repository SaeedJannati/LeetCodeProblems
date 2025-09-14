package LeetCode3541FindMostFrequentVowelAndConsonant

func maxFreqSum(s string) int {
	frequencies := make([]int, 26)
	vowels := map[byte]struct{}{'a': {}, 'e': {}, 'i': {}, 'o': {}, 'u': {}}
	maxVowelFreq := 0
	maxConsonantFreq := 0
	currentFreq := 0
	for _, c := range s {
		frequencies[c-'a']++
		currentFreq = frequencies[c-'a']
		if _, exists := vowels[byte(c)]; exists {
			maxVowelFreq = max(maxVowelFreq, currentFreq)
			continue
		}
		maxConsonantFreq = max(maxConsonantFreq, currentFreq)
	}
	return maxVowelFreq + maxConsonantFreq
}
