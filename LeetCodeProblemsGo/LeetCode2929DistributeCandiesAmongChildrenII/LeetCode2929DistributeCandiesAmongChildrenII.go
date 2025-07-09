package LeetCode2929DistributeCandiesAmongChildrenII

func distributeCandies(n int, limit int) int64 {
	minLimit := limit
	if n < limit {
		minLimit = n
	}
	var result int64 = 0
	var stepSum int64 = 0
	for i := 0; i <= minLimit; i++ {
		stepSum = int64(max(min(n, i+minLimit)-max(i, n-minLimit)+1, 0))
		result += stepSum
	}
	return result
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
