package main

func findWordsContaining(words []string, x byte) []int {
	length := len(words)
	result := []int{}
	runeX := rune(x)
	for i := 0; i < length; i++ {
		for _, c := range words[i] {
			if c == runeX {
				result = append(result, i)
				break
			}
		}
	}
	return result
}
