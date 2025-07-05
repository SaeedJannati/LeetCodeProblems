package LeetCode1394FindLuckyIntegerInAnArray

func findLucky(arr []int) int {
	frequencies := make(map[int]int)
	for _, num := range arr {
		frequencies[num]++
	}
	max := -1
	for key, value := range frequencies {
		if key != value {
			continue
		}
		if key > max {
			max = key
		}
	}
	return max
}
