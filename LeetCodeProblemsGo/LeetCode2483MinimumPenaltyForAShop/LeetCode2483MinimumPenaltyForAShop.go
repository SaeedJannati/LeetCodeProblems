package LeetCode2483MinimumPenaltyForAShop

func bestClosingTime(customers string) int {
	length := len(customers)
	prefixSums := make([]int, length+1)
	suffixSums := make([]int, length+1)
	for i := 1; i <= length; i++ {
		prefixSums[i] = prefixSums[i-1]
		if customers[i-1] == 'N' {
			prefixSums[i]++
		}
	}
	for i := length - 1; i >= 0; i-- {
		suffixSums[i] = suffixSums[i+1]
		if customers[i] == 'Y' {
			suffixSums[i]++
		}
	}
	minIndex := 0
	minPenalty := length
	for i := 0; i <= length; i++ {
		if prefixSums[i]+suffixSums[i] < minPenalty {
			minPenalty = prefixSums[i] + suffixSums[i]
			minIndex = i
		}
	}
	return minIndex
}
