package LeetCode1353MaximumNumberOfEventsThatCanBeAttended

import (
	"container/heap"
	"sort"
)

func maxEvents(events [][]int) int {
	sort.Slice(events, func(i, j int) bool {
		if events[i][0] == events[j][0] {
			return events[i][1] < events[j][1]
		}
		return events[i][0] < events[j][0]
	})
	length := len(events)
	maxDay := events[length-1][1]
	minHeap := &minHeap{}
	heap.Init(minHeap)
	coveredEvents := 0
	eventIndex := 0
	for day := 1; day <= maxDay; day++ {
		for eventIndex < length && events[eventIndex][0] <= day {
			if events[eventIndex][1] > maxDay {
				maxDay = events[eventIndex][1]
			}
			heap.Push(minHeap, events[eventIndex])
			eventIndex++
		}
		for !minHeap.IsEmpty() && minHeap.Top()[1] < day {
			heap.Pop(minHeap)
		}
		if !minHeap.IsEmpty() {
			heap.Pop(minHeap)
			coveredEvents++
		}

	}
	return coveredEvents
}

type minHeap [][]int

func (h *minHeap) Len() int {
	return len(*h)
}
func (h *minHeap) Less(i, j int) bool {
	return (*h)[i][1] < (*h)[j][1]
}
func (h *minHeap) Swap(i, j int) {
	(*h)[i], (*h)[j] = (*h)[j], (*h)[i]
}
func (h *minHeap) Push(x any) {
	*h = append(*h, x.([]int))
}
func (h *minHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
func (h *minHeap) Top() []int {
	if len(*h) == 0 {
		return nil
	}
	return (*h)[0]
}
func (h *minHeap) IsEmpty() bool {
	return len(*h) == 0
}
