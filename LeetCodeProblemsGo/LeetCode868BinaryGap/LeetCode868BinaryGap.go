package LeetCode868BinaryGap

func binaryGap(n int) int {
	lastOne := -1
	maxGap := 0
	currentGap := 0
	for i := 0; i < 32; i++ {
		if n&(1<<i) > 0 {
			if lastOne >= 0 {
				currentGap = i - lastOne
				maxGap = max(maxGap, currentGap)
			}
			lastOne = i
		}
	}
	return maxGap
}
