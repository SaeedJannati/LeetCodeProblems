package main

import (
	"container/heap"
	"math"
)

func countPaths(n int, roads [][]int) int {
	distances := make([]int64, n)
	for i := range distances {
		distances[i] = math.MaxInt
	}
	distances[0] = 0
	adjPlus := make(map[int]map[int]int)
	for i := 0; i < n; i++ {
		adjPlus[i] = make(map[int]int)
	}
	for _, edge := range roads {
		adjPlus[edge[0]][edge[1]] = edge[2]
		adjPlus[edge[1]][edge[0]] = edge[2]
	}
	minHeap := &MinHeapDistanceNodeItem{}
	heap.Init(minHeap)
	heap.Push(minHeap, &DistanceNodeItem{distance: 0, node: 0})
	var newDistance int64
	for minHeap.Len() > 0 {
		nodeInfo := heap.Pop(minHeap).(*DistanceNodeItem)
		if nodeInfo.distance > distances[nodeInfo.node] {
			continue
		}
		for key, value := range adjPlus[nodeInfo.node] {
			newDistance = distances[nodeInfo.node] + int64(value)
			if newDistance >= distances[key] {
				continue
			}
			distances[key] = newDistance
			heap.Push(minHeap, &DistanceNodeItem{distance: newDistance, node: key})
		}
	}
	adjMinus := make(map[int][]int)
	for _, edge := range roads {
		if distances[edge[0]]+int64(edge[2]) == distances[edge[1]] {
			if _, exists := adjMinus[edge[1]]; !exists {
				adjMinus[edge[1]] = []int{}
			}
			adjMinus[edge[1]] = append(adjMinus[edge[1]], edge[0])
		}
		if distances[edge[1]]+int64(edge[2]) == distances[edge[0]] {
			if _, exists := adjMinus[edge[0]]; !exists {
				adjMinus[edge[0]] = []int{}
			}
			adjMinus[edge[0]] = append(adjMinus[edge[0]], edge[1])
		}
	}
	memoisation := make(map[int]int)
	memoisation[0] = 1
	return CalculateWayCounts(adjMinus, memoisation, n-1)
}
func CalculateWayCounts(adjMinus map[int][]int, memoisation map[int]int, node int) int {
	if value, exists := memoisation[node]; exists {
		return value
	}
	var result int64
	if _, exists := adjMinus[node]; !exists {
		return 0
	}
	for _, vert := range adjMinus[node] {
		result += int64(CalculateWayCounts(adjMinus, memoisation, vert))
		result %= 1_000_000_007
	}
	memoisation[node] = int(result % 1_000_000_007)
	return memoisation[node]
}

type DistanceNodeItem struct {
	distance int64
	node     int
	index    int
}

type MinHeapDistanceNodeItem []*DistanceNodeItem

func (minHeap MinHeapDistanceNodeItem) Len() int {
	return len(minHeap)
}
func (minHeap MinHeapDistanceNodeItem) Less(i, j int) bool {
	return minHeap[i].distance < minHeap[j].distance
}
func (minHeap MinHeapDistanceNodeItem) Swap(i, j int) {
	minHeap[i], minHeap[j] = minHeap[j], minHeap[i]
}

func (minHeap *MinHeapDistanceNodeItem) Push(x any) {
	length := len(*minHeap)
	item := x.(*DistanceNodeItem)
	item.index = length
	*minHeap = append(*minHeap, item)
}

func (minHeap *MinHeapDistanceNodeItem) Pop() any {
	old := *minHeap
	length := len(*minHeap)
	item := old[length-1]
	old[length-1] = nil
	item.index = -1
	*minHeap = old[:length-1]
	return item
}
