package LeetCode781RabbitsInForest

func numRabbits(answers []int) int {
	countMap := make(map[int]int)
	for _, num := range answers {
		if _, exists := countMap[num]; !exists {
			countMap[num] = 0
		}
		countMap[num]++
	}
	result := 0
	var delta int
	for key, value := range countMap {
		delta = value / (key + 1)
		if value%(key+1) != 0 {
			delta++
		}
		result += delta * (key + 1)
	}
	return result
}
