package LeetCode3136ValidWord

func isValid(word string) bool {
	length := len(word)
	if length < 3 {
		return false
	}
	vowelCount := 0
	consonantCount := 0
	for _, char := range word {
		if !isValidCharacter(char) {
			return false
		}
		if isVowel(char) {
			vowelCount++
		}
		if isConsonant(char) {
			consonantCount++
		}
	}
	if vowelCount < 1 || consonantCount < 1 {
		return false
	}
	return true
}

func isLetter(b rune) bool {
	if b >= 'a' && b <= 'z' {
		return true
	}
	if b >= 'A' && b <= 'Z' {
		return true
	}
	return false
}
func isVowel(b rune) bool {
	if b == 'a' || b == 'e' || b == 'i' || b == 'u' || b == 'o' {
		return true
	}
	if b == 'A' || b == 'E' || b == 'I' || b == 'U' || b == 'O' {
		return true
	}
	return false
}
func isConsonant(b rune) bool {
	if isVowel(b) {
		return false
	}
	if !isLetter(b) {
		return false
	}
	return true
}
func isValidCharacter(b rune) bool {
	if isLetter(b) {
		return true
	}
	if b >= '0' && b <= '9' {
		return true
	}
	return false
}
