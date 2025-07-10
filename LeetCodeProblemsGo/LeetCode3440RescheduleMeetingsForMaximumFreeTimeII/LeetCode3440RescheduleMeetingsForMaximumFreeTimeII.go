package LeetCode3440RescheduleMeetingsForMaximumFreeTimeII

import (
	"fmt"
	"sort"
)

func maxFreeTime(eventTime int, startTime []int, endTime []int) int {
	result := 0
	current := 0
	length := len(startTime)
	nextStartTime := 0
	lastDelay := startTime[0]
	delays := make([][]int, length+1)
	delays[0] = []int{0, lastDelay}
	for i := 0; i < length; i++ {
		current = lastDelay
		nextStartTime = eventTime
		if i < length-1 {
			nextStartTime = startTime[i+1]
		}
		lastDelay = nextStartTime - endTime[i]
		current += lastDelay
		if current > result {
			result = current
		}
		delays[i+1] = []int{i + 1, lastDelay}
	}
	sort.Slice(delays, func(i, j int) bool {
		return delays[i][1] > delays[j][1]
	})
	var found bool
	var eventLength int
	lastEndTime := 0
	for i := 0; i < length; i++ {
		found = false
		eventLength = endTime[i] - startTime[i]
		for j := 0; j < 3; j++ {
			if delays[j][0] == i || delays[j][0] == i+1 {
				continue
			}
			if delays[j][1] >= eventLength {
				found = true
				break
			}
		}
		if !found {
			lastEndTime = endTime[i]
			continue
		}
		nextStartTime = eventTime
		if i < length-1 {
			nextStartTime = startTime[i+1]
		}
		current = nextStartTime - lastEndTime
		if current > result {
			result = current
		}
		lastEndTime = endTime[i]
	}
	return result

}

func Calculate() {
	eventTime := 10
	startTime := []int{0, 7, 9}
	endTime := []int{1, 8, 10}
	fmt.Println(maxFreeTime(eventTime, startTime, endTime))
}
