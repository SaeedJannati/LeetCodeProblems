package LeetCode2273FindResultantArrayAfterRemovingAnagrams

func getWordMap(word string) map[rune]int {
	result := map[rune]int{}
	for _, char := range word {
		result[char]++
	}
	return result
}
func areEquals(first, second map[rune]int) bool {
	if len(first) != len(second) {
		return false
	}
	for key, value := range first {
		if _, ok := second[key]; !ok {
			return false
		}
		if second[key] != value {
			return false
		}
	}
	return true
}
func removeAnagrams(words []string) []string {
	previousWord := words[0]
	previousMap := getWordMap(previousWord)
	uniquePointer := 0
	length := len(words)
	for i := 1; i < length; i++ {
		currentMap := getWordMap(words[i])
		if areEquals(previousMap, currentMap) {
			continue
		}
		uniquePointer++
		previousWord = words[i]
		previousMap = getWordMap(previousWord)
		words[i], words[uniquePointer] = words[uniquePointer], words[i]
	}
	words = words[:uniquePointer+1]
	return words
}
