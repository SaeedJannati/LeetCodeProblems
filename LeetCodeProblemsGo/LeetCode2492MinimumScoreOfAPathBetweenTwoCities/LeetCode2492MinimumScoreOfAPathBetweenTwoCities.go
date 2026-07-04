package LeetCode2492MinimumScoreOfAPathBetweenTwoCities

import "math"

func minScore(n int, roads [][]int) int {
	parents := make([]int, n+1)
	ranks := make([]int, n+1)
	for i := 1; i <= n; i++ {
		parents[i] = i
		ranks[i] = math.MaxInt32
	}

	for _, road := range roads {
		ranks[road[0]] = min(ranks[road[0]], road[2])
		ranks[road[1]] = min(ranks[road[1]], road[2])
	}
	for _, road := range roads {
		union(parents, ranks, road[0], road[1])
	}
	return ranks[find(parents, 1)]
}
func find(parents []int, node int) int {
	if parents[node] != node {
		parents[node] = find(parents, parents[node])
	}
	return parents[node]
}
func union(parents, ranks []int, first, second int) {
	firstRoot := find(parents, first)
	secondRoot := find(parents, second)
	if ranks[firstRoot] < ranks[secondRoot] {
		parents[secondRoot] = firstRoot
		find(parents, secondRoot)
		return
	}
	parents[firstRoot] = secondRoot
	find(parents, firstRoot)
}
