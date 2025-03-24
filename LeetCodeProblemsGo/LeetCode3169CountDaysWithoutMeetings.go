package main

import "sort"

func countDays(days int, meetings [][]int) int {
	sort.Slice(meetings, func(i, j int) bool {
		return meetings[i][0] < meetings[j][0]
	})
	meetingsMerged := [][]int{}
	meetingsLength := len(meetings)
	for i := 0; i < meetingsLength; i++ {
		begin := meetings[i][0]
		end := meetings[i][1]
		for i < meetingsLength-1 && end >= meetings[i+1][0] {
			end = max(end, meetings[i+1][1])
			i++
		}
		meetingsMerged = append(meetingsMerged, []int{begin, end})
	}
	var result int
	mergedLength := len(meetingsMerged)
	for i := 0; i < mergedLength-1; i++ {
		result += meetingsMerged[i+1][0] - meetingsMerged[i][1] - 1
	}
	result += meetingsMerged[0][0] - 1
	result += max(0, days-meetingsMerged[mergedLength-1][1])
	return result
}
