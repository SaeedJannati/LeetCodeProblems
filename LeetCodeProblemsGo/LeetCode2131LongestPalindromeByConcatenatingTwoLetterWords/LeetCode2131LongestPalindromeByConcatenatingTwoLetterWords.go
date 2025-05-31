package main

func longestPalindrome(words []string) int {
	var aChar byte = 'a'
	countMap := make(map[int]int)
	reverseCountMap := make(map[int]int)
	sameLettersMap := make(map[byte]int)
	var mask int
	var reverseMask int
	for _, word := range words {
		if word[0] == word[1] {
			sameLettersMap[word[0]]++
			continue
		}
		mask = (int(word[0])-int(aChar))*26 + (int(word[1]) - int(aChar))
		reverseMask = (int(word[1])-int(aChar))*26 + (int(word[0]) - int(aChar))
		countMap[mask]++
		reverseCountMap[reverseMask]++

	}
	chosenPairCount := 0
	var minPairCount int
	for mask, count := range countMap {
		if _, exists := reverseCountMap[mask]; !exists {
			continue
		}
		minPairCount = count
		if reverseCountMap[mask] < minPairCount {
			minPairCount = reverseCountMap[mask]
		}
		chosenPairCount += minPairCount
	}
	var chosenSingleSame bool = false
	for _, count := range sameLettersMap {
		chosenPairCount += (count / 2) * 2
		if chosenSingleSame {
			continue
		}
		if count%2 == 1 {
			chosenSingleSame = true
			chosenPairCount++
		}
	}
	return chosenPairCount * 2
}
