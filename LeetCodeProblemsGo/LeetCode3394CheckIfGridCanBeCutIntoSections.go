package main

import "sort"

func checkValidCuts(n int, rectangles [][]int) bool {
	sort.Slice(rectangles, func(i, j int) bool {
		return rectangles[i][0] < rectangles[j][0]
	})
	length := len(rectangles)
	mergedCounts := 0
	end := 0
	for i := 0; i < length; i++ {
		end = rectangles[i][2]
		for i < length-1 && end > rectangles[i+1][0] {
			end = max(end, rectangles[i+1][2])
			i++
		}
		mergedCounts++
	}
	if mergedCounts > 2 {
		return true
	}
	sort.Slice(rectangles, func(i, j int) bool {
		return rectangles[i][1] < rectangles[j][1]
	})
	mergedCounts = 0
	for i := 0; i < length; i++ {
		end = rectangles[i][3]
		for i < length-1 && end > rectangles[i+1][1] {
			end = max(end, rectangles[i+1][3])
			i++
		}
		mergedCounts++
	}
	if mergedCounts > 2 {
		return true
	}
	return false
}
