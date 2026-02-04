package LeetCode3640TrionicArrayII

import (
	"fmt"
	"math"
)

type partInfo struct {
	Slope           int
	Sum             int64
	StartIndex      int
	EndIndex        int
	MaxSumFromStart int64
	MaxSumFromEnd   int64
}

func maxSumTrionic(nums []int) int64 {
	previous := nums[0]
	slopeSum := []partInfo{}
	delta := 0
	slope := 0
	length := len(nums)
	slopeSumLength := 0
	for i := 1; i < length; i++ {
		delta = nums[i] - previous
		if delta == 0 {
			slope = 0
		} else if delta > 0 {
			slope = 1
		} else {
			slope = -1
		}
		if len(slopeSum) == 0 {
			slopeSum = append(slopeSum, partInfo{
				Slope:           slope,
				Sum:             int64(previous + nums[i]),
				MaxSumFromStart: int64(previous + nums[i]),
				StartIndex:      i - 1,
			})

			previous = nums[i]
			continue
		}
		slopeSumLength = len(slopeSum) - 1
		if slope == slopeSum[slopeSumLength].Slope {
			slopeSum[slopeSumLength].Sum += int64(nums[i])
			slopeSum[slopeSumLength].MaxSumFromStart = max(slopeSum[slopeSumLength].Sum, slopeSum[slopeSumLength].MaxSumFromStart)
			previous = nums[i]
			continue
		}
		if slope != slopeSum[slopeSumLength].Slope {
			slopeSum[slopeSumLength].EndIndex = i - 1
			slopeSum = append(slopeSum, partInfo{
				Slope:           slope,
				Sum:             int64(previous + nums[i]),
				MaxSumFromStart: int64(previous + nums[i]),
				StartIndex:      i - 1,
			})

			previous = nums[i]
			continue
		}

		previous = nums[i]
	}
	slopeSum[slopeSumLength].EndIndex = length - 1
	var maxSum int64 = math.MinInt64
	for i, e := 0, len(slopeSum)-2; i < e; i++ {
		if slopeSum[i].Slope != 1 {
			continue
		}
		if slopeSum[i+1].Slope != -1 {
			continue
		}
		slopeSum[i].MaxSumFromEnd = int64(nums[slopeSum[i].EndIndex] + nums[slopeSum[i].EndIndex-1])
		newSum := slopeSum[i].MaxSumFromEnd
		for j := slopeSum[i].EndIndex - 2; j >= slopeSum[i].StartIndex; j-- {
			newSum += int64(nums[j])
			slopeSum[i].MaxSumFromEnd = max(slopeSum[i].MaxSumFromEnd, newSum)
		}
	}
	for i, e := 1, len(slopeSum)-1; i < e; i++ {
		if slopeSum[i].Slope != -1 {
			continue
		}
		if slopeSum[i-1].Slope != 1 || slopeSum[i+1].Slope != 1 {
			continue
		}
		maxSum = max(maxSum, slopeSum[i-1].MaxSumFromEnd+slopeSum[i].Sum+slopeSum[i+1].MaxSumFromStart-int64(nums[slopeSum[i].StartIndex]+nums[slopeSum[i+1].StartIndex]))
	}
	return maxSum
}

func Calculate() {
	nums := []int{0, -2, -1, -3, 0, 2, -1}
	//{2, 993, -791, -635, -569}
	fmt.Println(maxSumTrionic(nums))
}
