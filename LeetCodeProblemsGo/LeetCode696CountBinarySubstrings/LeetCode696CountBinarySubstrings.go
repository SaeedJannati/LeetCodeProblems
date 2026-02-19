package LeetCode696CountBinarySubstrings

func countBinarySubstrings(s string) int {
	result := 0
	length := len(s)
	firstPointer := 0
	var firstRune byte = '0'
	var secondRune byte = '1'
	for i := 1; i < length; i++ {
		if s[i] == s[i-1] {
			continue
		}
		firstPointer = i - 1
		firstRune = s[firstPointer]
		secondRune = s[i]
		for i < length && firstPointer >= 0 && s[i] == secondRune && s[firstPointer] == firstRune {
			result++
			firstPointer--
			i++
		}
		i--
	}
	return result
}
