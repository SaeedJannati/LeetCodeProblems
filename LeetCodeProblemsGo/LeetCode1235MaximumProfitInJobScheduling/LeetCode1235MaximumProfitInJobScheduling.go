package LeetCode1235MaximumProfitInJobScheduling

import (
	"sort"
)

func getMaxProfitAt(jobs [][]int, dp []int, length, index int) int {
	if dp[index] > 0 {
		return dp[index]
	}
	nextIndex := length
	begin := index + 1
	end := length - 1
	var mid int
	for begin <= end {
		mid = (begin + end) >> 1
		if jobs[mid][0] >= jobs[index][1] {
			nextIndex = min(nextIndex, mid)
			end = mid - 1
			continue
		}
		begin = mid + 1
	}
	if nextIndex == length {
		if index == length-1 {
			dp[index] = jobs[index][2]
			return dp[index]
		}
		dp[index] = max(jobs[index][2], getMaxProfitAt(jobs, dp, length, index+1))
		return dp[index]
	}
	dp[index] = max(jobs[index][2]+getMaxProfitAt(jobs, dp, length, nextIndex), getMaxProfitAt(jobs, dp, length, index+1))
	return dp[index]
}
func jobScheduling(startTime []int, endTime []int, profit []int) int {
	length := len(startTime)
	jobs := make([][]int, length)
	for i := 0; i < length; i++ {
		jobs[i] = []int{startTime[i], endTime[i], profit[i]}
	}
	sort.Slice(jobs, func(i, j int) bool {
		return jobs[i][0] < jobs[j][0]
	})
	dp := make([]int, length)
	return getMaxProfitAt(jobs, dp, length, 0)
}
