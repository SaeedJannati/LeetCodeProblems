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

// tabulation with no recurse

// func mostPoints(questions [][]int) int64 {
// 	length := len(questions)
// 	dp := make([]int64, length)
// 	var next int64
// 	var allowedNext int64
// 	for i := length - 1; i >= 0; i-- {
// 		next = 0
// 		allowedNext = 0
// 		if i < length-1 {
// 			next = dp[i+1]
// 		}
// 		if i+questions[i][1] < length-1 {
// 			allowedNext = dp[i+questions[i][1]+1]
// 		}
// 		dp[i] = max(next,
// 			int64(questions[i][0])+allowedNext)
// 	}
// 	return dp[0]
// }
