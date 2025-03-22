package main

func countCompleteComponents(n int, edges [][]int) int {
	ranks := make([]int, n)
	parents := make([]int, n)
	for i := 0; i < n; i++ {
		parents[i] = i
	}
	for _, edge := range edges {
		Union(parents, ranks, edge[0], edge[1])
	}
	for i := 0; i < n; i++ {
		parents[i] = Find(parents, i)
	}
	result := 0
	segments := make(map[int]map[int]bool)
	segmentsEdgeCount := make(map[int]int)
	for i := 0; i < n; i++ {
		if _, exists := segments[parents[i]]; !exists {
			segments[parents[i]] = make(map[int]bool)
			segmentsEdgeCount[i] = 0
		}
		segments[parents[i]][i] = true
	}
	edgeParent := 0
	for _, edge := range edges {
		edgeParent = Find(parents, edge[0])
		segmentsEdgeCount[edgeParent]++
	}
	edgeCount := 0
	vertCount := 0
	for key, value := range segments {
		edgeCount = segmentsEdgeCount[key]
		vertCount = len(value)
		if edgeCount == vertCount*(vertCount-1)/2 {
			result++
		}

	}
	return result
}

func Find(parents []int, node int) int {
	if parents[node] != node {
		parents[node] = Find(parents, parents[node])
	}
	return parents[node]
}

func Union(parents []int, ranks []int, first int, second int) {
	firstParent := Find(parents, first)
	secondParent := Find(parents, second)
	if firstParent == secondParent {
		return
	}
	if ranks[firstParent] > ranks[secondParent] {
		parents[secondParent] = firstParent
	} else if ranks[secondParent] > ranks[firstParent] {
		parents[firstParent] = secondParent
	} else {
		parents[secondParent] = firstParent
		ranks[firstParent]++
	}
}
