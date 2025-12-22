package LeetCode960DeleteColumnsToMakeSortedIII

func getLis(strs []string, dp []int, height, index int) int {
	if dp[index] != -1 {
		return dp[index]
	}
	isCandidate := false
	dp[index] = 1
	for i := 0; i < index; i++ {
		isCandidate = true
		for row := 0; row < height; row++ {
			if strs[row][i] > strs[row][index] {
				isCandidate = false
				continue
			}
		}
		if isCandidate {
			dp[index] = max(dp[index], getLis(strs, dp, height, i)+1)
		}
	}
	return dp[index]
}
func minDeletionSize(strs []string) int {
	height := len(strs)
	width := len(strs[0])
	dp := make([]int, width)
	for i := 0; i < width; i++ {
		dp[i] = -1
	}
	maxLis := 0
	for i := 0; i < width; i++ {
		maxLis = max(maxLis, getLis(strs, dp, height, i))
	}
	return width - maxLis

}
func Calculate() {
	strs := []string{"abbba"}
	result := minDeletionSize(strs)
	println(result)
}
