package LeetCode1039MinimumScoreTriangulationOfPolygon

func findTriangulation(values []int, memoisation [][]int, start int, end int) int {
	if memoisation[start][end] != -1 {
		return memoisation[start][end]
	}
	if end-start < 2 {
		memoisation[start][end] = 0
		return 0
	}
	if end-start == 2 {
		memoisation[start][end] = values[start] * values[start+1] * values[end]
		return memoisation[start][end]
	}
	minScore := 1<<31 - 1
	var score int
	for i := start + 1; i < end; i++ {
		score = values[start] * values[i] * values[end]
		score += findTriangulation(values, memoisation, start, i)
		score += findTriangulation(values, memoisation, i, end)
		minScore = min(minScore, score)
	}
	memoisation[start][end] = minScore
	return minScore
}

func minScoreTriangulation(values []int) int {
	length := len(values)
	memoisation := make([][]int, length)
	for i := 0; i < length; i++ {
		memoisation[i] = make([]int, length)
		for j := 0; j < length; j++ {
			memoisation[i][j] = -1
		}
	}
	return findTriangulation(values, memoisation, 0, length-1)
}
