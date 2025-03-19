package main

import (
	"fmt"
	"unicode"
)

func printScriptName(rawScriptName string) {
	name := convertScriptName(rawScriptName)
	commitName := "feat: add " + name
	fmt.Println(name)
	fmt.Println(commitName)
}

func convertScriptName(rawScriptName string) string {
	var result string
	runes := []rune(rawScriptName)
	rawLength := len(runes)
	for i := 0; i < rawLength; i++ {
		if runes[i] == ' ' && i+1 < rawLength {
			result += string(unicode.ToUpper(runes[i+1]))
			i++
			continue
		}
		if runes[i] != ' ' && runes[i] != '-' && runes[i] != '.' &&
			runes[i] != '(' && runes[i] != ')' && runes[i] != '[' &&
			runes[i] != ']' && runes[i] != '{' && runes[i] != '}' &&
			runes[i] != '\'' {
			result += string(runes[i])
		}
	}
	result = "LeetCode" + result
	return result
}
