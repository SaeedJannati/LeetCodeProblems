package main

import (
	"math"
)

func closestMeetingNode(edges []int, node1 int, node2 int) int {
	length := len(edges)
	visited := make([]bool, length)
	distanceFromFirstNode := make([]int, length)
	distanceFromSecondNode := make([]int, length)
	for i := 0; i < length; i++ {
		distanceFromFirstNode[i] = -1
		distanceFromSecondNode[i] = -1
	}
	distanceFromFirstNode[node1] = 0
	visited[node1] = true
	dfs(edges, visited, distanceFromFirstNode, node1, 1)
	visited = make([]bool, length)
	visited[node2] = true
	distanceFromSecondNode[node2] = 0
	dfs(edges, visited, distanceFromSecondNode, node2, 1)
	minMaxDistance := math.MaxInt32
	var destNode int
	for i := 0; i < length; i++ {
		if distanceFromFirstNode[i] == -1 {
			continue
		}
		if distanceFromSecondNode[i] == -1 {
			continue
		}
		maxDistance := distanceFromFirstNode[i]
		if distanceFromSecondNode[i] > maxDistance {
			maxDistance = distanceFromSecondNode[i]
		}
		if maxDistance < minMaxDistance {
			minMaxDistance = maxDistance
			destNode = i
		}
	}
	if minMaxDistance == math.MaxInt32 {
		return -1
	}
	return destNode
}
func dfs(edges []int, visited []bool, distancesFrom []int, node int, distance int) {
	next := edges[node]
	if next == -1 {
		return
	}
	if visited[next] {
		return
	}
	visited[next] = true
	distancesFrom[next] = distance
	dfs(edges, visited, distancesFrom, next, distance+1)
}
