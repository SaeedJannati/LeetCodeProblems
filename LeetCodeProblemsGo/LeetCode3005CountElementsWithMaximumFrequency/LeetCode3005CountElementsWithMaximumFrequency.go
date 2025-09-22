package LeetCode3005CountElementsWithMaximumFrequency

func maxFrequencyElements(nums []int) int {
	frequencies := make(map[int]int)
	maxFrequency := 0
	maxFreqOccurrences := 0
	for _, num := range nums {
		if _, exists := frequencies[num]; !exists {
			frequencies[num] = 0
		}
		frequencies[num]++
		if frequencies[num] > maxFrequency {
			maxFreqOccurrences = 1
			maxFrequency = frequencies[num]
			continue
		}
		if frequencies[num] == maxFrequency {
			maxFreqOccurrences++
		}
	}
	return maxFreqOccurrences * maxFrequency

}
