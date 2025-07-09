package LeetCode1751MaximumNumberOfEventsThatCanBeAttendedII

import "sort"

func calculate(events, memoisation [][]int, k, length, index, eventsChosenCount int) int {
	if index >= length {
		return 0
	}
	if eventsChosenCount >= k {
		return 0
	}
	if memoisation[index][eventsChosenCount] != -1 {
		return memoisation[index][eventsChosenCount]
	}
	endDay := events[index][1]
	begin := index + 1
	end := length - 1
	var mid int
	found := length
	for begin <= end {
		mid = (begin + end) / 2
		if events[mid][0] > endDay {
			found = mid
			end = mid - 1
			continue
		}
		begin = mid + 1
	}
	pick := events[index][2]
	if found < length {
		pick += calculate(events, memoisation, k, length, found, eventsChosenCount+1)
	}
	memoisation[index][eventsChosenCount] = pick
	skip := 0
	if index+1 < length {
		skip = calculate(events, memoisation, k, length, index+1, eventsChosenCount)
	}
	if skip > pick {
		memoisation[index][eventsChosenCount] = skip
	}
	return memoisation[index][eventsChosenCount]
}
func maxValue(events [][]int, k int) int {
	length := len(events)
	sort.Slice(events, func(i, j int) bool {
		return events[i][0] < events[j][0]
	})
	memoisation := make([][]int, length)
	for i := 0; i < length; i++ {
		memoisation[i] = make([]int, k+1)
		for j := 0; j <= k; j++ {
			memoisation[i][j] = -1
		}
	}
	return calculate(events, memoisation, k, length, 0, 0)
}
