package LeetCode1957DeleteCharactersToMakeFancyString

import "strings"

func makeFancyString(s string) string {
	var builder strings.Builder
	consecutiveCount := 0
	var currentChar rune = 0
	for _, char := range s {
		if char != currentChar {
			consecutiveCount = 1
			currentChar = char

		} else {
			consecutiveCount++
		}
		if consecutiveCount < 3 {
			builder.WriteString(string(char))
		}
	}
	return builder.String()
}
