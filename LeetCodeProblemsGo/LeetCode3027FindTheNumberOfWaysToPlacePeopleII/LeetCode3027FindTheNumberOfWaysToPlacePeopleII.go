package LeetCode3027FindTheNumberOfWaysToPlacePeopleII

import (
	"math"
	"sort"
)

func numberOfPairs(points [][]int) int {
	sort.Slice(points, func(a, b int) bool {
		if points[a][0] == points[b][0] {
			return points[a][1] > points[b][1]
		}
		return points[a][0] < points[b][0]
	})
	result := 0
	length := len(points)
	for i := 0; i < length; i++ {
		lastMatched := math.MinInt
		for j := i + 1; j < length; j++ {
			if points[j][1] <= points[i][1] && points[j][1] > lastMatched {
				result++
				lastMatched = points[j][1]
			}
		}
	}
	return result
}
