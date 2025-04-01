package leetcode2140solvingquestionswithbrainpower

func mostPoints(questions [][]int) int64 {
	length := len(questions)
	dp := make([]int64, length)
	for i := length - 1; i >= 0; i-- {
		getPointsAt(questions, dp, length, i)
	}
	return dp[0]
}

func getPointsAt(questions [][]int, dp []int64, length int, index int) int64 {
	if index >= length {
		return 0
	}
	if dp[index] != 0 {
		return dp[index]
	}
	dp[index] = max(getPointsAt(questions, dp, length, index+1),
		int64(questions[index][0])+
			getPointsAt(questions, dp, length, index+questions[index][1]+1))
	return dp[index]
}
