package LeetCode1128NumberOfEquivalentDominoPairs

func numEquivDominoPairs(dominoes [][]int) int {
	var larger int
	smaller := 0
	dominoesMap := make(map[int]map[int]int, 9)
	for _, domino := range dominoes {
		if domino[0] > domino[1] {
			larger = domino[0]
			smaller = domino[1]
		} else {
			larger = domino[1]
			smaller = domino[0]
		}
		if _, ok := dominoesMap[larger]; !ok {
			dominoesMap[larger] = make(map[int]int, 9)
		}
		if _, ok := dominoesMap[larger][smaller]; !ok {
			dominoesMap[larger][smaller] = 0
		}
		dominoesMap[larger][smaller]++
	}
	result := 0
	for _, v := range dominoesMap {
		for _, count := range v {
			result += count * (count - 1) / 2
		}
	}
	return result
}
