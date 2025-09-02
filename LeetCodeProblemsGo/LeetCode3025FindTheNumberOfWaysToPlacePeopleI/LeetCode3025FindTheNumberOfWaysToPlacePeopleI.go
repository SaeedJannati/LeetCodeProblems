package LeetCode3025FindTheNumberOfWaysToPlacePeopleI

import "sort"

func numberOfPairs(points [][]int) int {
	length := len(points)
	sort.Slice(points, func(i, j int) bool {
		if points[i][0] == points[j][0] {
			return points[i][1] > points[j][1]
		}
		return points[i][0] < points[j][0]
	})
	result := 0
	for i := 0; i < length; i++ {
		lastMatchedY := -1
		for j := i + 1; j < length; j++ {
			if points[j][1] <= points[i][1] && points[j][1] > lastMatchedY {
				result++
				lastMatchedY = points[j][1]
			}
		}
	}
	return result
}
