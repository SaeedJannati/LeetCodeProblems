package main

func maxTargetNodes(edges1 [][]int, edges2 [][]int, k int) []int {
	n := len(edges1) + 1
	m := len(edges2) + 1
	result := make([]int, n)
	for i := 0; i < n; i++ {
		result[i] = 1
	}
	if k == 0 {
		return result
	}
	visitedLen := n
	if m > n {
		visitedLen = m
	}
	adjPlusFirst := make(map[int][]int)
	for _, edge := range edges1 {
		if _, exists := adjPlusFirst[edge[0]]; !exists {
			adjPlusFirst[edge[0]] = make([]int, 0)
		}
		adjPlusFirst[edge[0]] = append(adjPlusFirst[edge[0]], edge[1])
		if _, exists := adjPlusFirst[edge[1]]; !exists {
			adjPlusFirst[edge[1]] = make([]int, 0)
		}
		adjPlusFirst[edge[1]] = append(adjPlusFirst[edge[1]], edge[0])
	}

	adjPlusSecond := make(map[int][]int)
	for _, edge := range edges2 {
		if _, exists := adjPlusSecond[edge[0]]; !exists {
			adjPlusSecond[edge[0]] = make([]int, 0)
		}
		adjPlusSecond[edge[0]] = append(adjPlusSecond[edge[0]], edge[1])

		if _, exists := adjPlusSecond[edge[1]]; !exists {
			adjPlusSecond[edge[1]] = make([]int, 0)
		}
		adjPlusSecond[edge[1]] = append(adjPlusSecond[edge[1]], edge[0])
	}
	visited := make([]bool, visitedLen)
	firstDistances := make([]int, n)
	for i := 0; i < n; i++ {
		visited = make([]bool, visitedLen)
		visited[i] = true
		nodeCount := 0
		dfs(adjPlusFirst, visited, i, k, 1, &nodeCount)
		firstDistances[i] = nodeCount
	}
	maxDistance := 0
	for i := 0; i < m; i++ {
		visited = make([]bool, visitedLen)
		visited[i] = true
		nodeCount := 0
		dfs(adjPlusSecond, visited, i, k-1, 1, &nodeCount)
		if nodeCount > maxDistance {
			maxDistance = nodeCount
		}
	}
	for i := 0; i < n; i++ {
		result[i] = firstDistances[i] + maxDistance
	}
	return result
}

func dfs(adjPlus map[int][]int, visited []bool, node int, maxDistance int, currentDistance int, nodeCount *int) {
	if currentDistance > maxDistance {
		return
	}
	(*nodeCount)++
	for _, neighbor := range adjPlus[node] {
		if visited[neighbor] {
			continue
		}
		visited[neighbor] = true
		dfs(adjPlus, visited, neighbor, maxDistance, currentDistance+1, nodeCount)
	}
}
