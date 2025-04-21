package LeetCode2145CountTheHiddenSequences

func numberOfArrays(differences []int, lower int, upper int) int {
	max := 0
	min := 0
	sum := 0
	for _, difference := range differences {
		sum += difference
		if sum > max {
			max = sum
		}
		if sum < min {
			min = sum
		}
	}
	if (max - min) > (upper - lower) {
		return 0
	}
	return (upper - lower) - (max - min) + 1
}
