package LeetCode2099FindSubsequenceOfLengthKWithTheLargestSum

import "container/heap"

func maxSubsequence(nums []int, k int) []int {
	h := &maxHeap{}
	heap.Init(h)
	indicesMap := make(map[int][]int)
	for i, num := range nums {
		heap.Push(h, num)
		if _, exists := indicesMap[num]; !exists {
			indicesMap[num] = []int{}
		}
		indicesMap[num] = append(indicesMap[num], i)
	}
	indicesHeap := &maxHeap{}
	heap.Init(indicesHeap)
	result := make([]int, k)
	index := 0
	for i := 0; i < k; i++ {
		poped := heap.Pop(h).(int)
		index = indicesMap[poped][0]
		indicesMap[poped] = indicesMap[poped][1:]
		heap.Push(indicesHeap, -index)
	}
	for i := 0; i < k; i++ {
		result[i] = nums[-heap.Pop(indicesHeap).(int)]
	}
	return result
}

type maxHeap []int

func (h maxHeap) Len() int {
	return len(h)
}

func (h maxHeap) Less(i, j int) bool {
	return h[i] > h[j]
}
func (h maxHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}
func (h *maxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}
func (h *maxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}
