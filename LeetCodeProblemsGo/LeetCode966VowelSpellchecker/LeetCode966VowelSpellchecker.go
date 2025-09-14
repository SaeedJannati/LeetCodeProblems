package LeetCode966VowelSpellchecker

import "strings"

func spellchecker(wordlist []string, queries []string) []string {
	caseSensitiveMap := make(map[string]struct{})
	caseInsensitiveMap := make(map[string]string)
	vowelErrorMap := make(map[string]string)
	for _, word := range wordlist {
		caseSensitiveMap[word] = struct{}{}
		lowerWord := strings.ToLower(word)
		if _, exists := caseInsensitiveMap[lowerWord]; !exists {
			caseInsensitiveMap[lowerWord] = word
		}
		vowelErrorWord := toVowelError(lowerWord)
		if _, exists := vowelErrorMap[vowelErrorWord]; !exists {
			vowelErrorMap[vowelErrorWord] = word
		}
	}
	result := make([]string, len(queries))
	for i, query := range queries {
		if _, exists := caseSensitiveMap[query]; exists {
			result[i] = query
			continue
		}
		lowerWord := strings.ToLower(query)
		if word, exists := caseInsensitiveMap[lowerWord]; exists {
			result[i] = word
			continue
		}
		vowelErrorWord := toVowelError(lowerWord)
		if word, exists := vowelErrorMap[vowelErrorWord]; exists {
			result[i] = word
			continue
		}
		result[i] = ""
	}
	return result
}
func toVowelError(s string) string {
	result := []byte(s)
	for i, e := 0, len(result); i < e; i++ {
		if !isVowel(result[i]) {
			continue
		}
		result[i] = '*'
	}
	return string(result)
}

func isVowel(c byte) bool {
	if c > 'Z' {
		c -= 32
	}
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
}

func Calculate() {
	wordlist := []string{"KiTe", "kite", "hare", "Hare"}
	queries := []string{"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"}
	result := spellchecker(wordlist, queries)
	for _, res := range result {
		println(res)
	}
}
