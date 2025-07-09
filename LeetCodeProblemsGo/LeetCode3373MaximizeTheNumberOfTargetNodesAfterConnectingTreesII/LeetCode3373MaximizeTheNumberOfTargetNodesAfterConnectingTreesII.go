package main

func maxTargetNodes(edges1 [][]int, edges2 [][]int) []int {
	adjPlusFirst := make(map[int][]int)
	adjPlusSecond := make(map[int][]int)
	fillAdjPlus(edges1, adjPlusFirst)
	fillAdjPlus(edges2, adjPlusSecond)
	n := len(edges1) + 1
	m := len(edges2) + 1
	firstColours := make([]int, n)
	firstCoulorsCount := make([]int, 2)
	secondCoulorsCount := make([]int, 2)
	visited := make([]bool, n)
	visited[0] = true
	firstColours[0] = 0
	firstCoulorsCount[0] = 1
	firstDfs(adjPlusFirst, visited, firstColours, firstCoulorsCount, 0, 1)
	visited = make([]bool, m)
	visited[0] = true
	secondCoulorsCount[0]++
	calcColourCountDfs(adjPlusSecond, visited, secondCoulorsCount, 0, 1)
	maxSecondColourCount := secondCoulorsCount[0]
	if secondCoulorsCount[1] > maxSecondColourCount {
		maxSecondColourCount = secondCoulorsCount[1]
	}
	result := make([]int, n)
	for i := 0; i < n; i++ {
		result[i] = maxSecondColourCount + firstCoulorsCount[firstColours[i]]
	}
	return result
}
func calcColourCountDfs(adjPlus map[int][]int, visited []bool, coloursCount []int, node int, colour int) {
	nextColour := 0
	if colour == 0 {
		nextColour = 1
	}
	for _, neighbor := range adjPlus[node] {
		if visited[neighbor] {
			continue
		}
		coloursCount[colour]++
		visited[neighbor] = true
		calcColourCountDfs(adjPlus, visited, coloursCount, neighbor, nextColour)
	}
}
func firstDfs(adjPlus map[int][]int, visited []bool, colours []int, coloursCount []int, node int, colour int) {
	nextColour := 0
	if colour == 0 {
		nextColour = 1
	}
	for _, neighbor := range adjPlus[node] {
		if visited[neighbor] {
			continue
		}
		colours[neighbor] = colour
		coloursCount[colour]++
		visited[neighbor] = true
		firstDfs(adjPlus, visited, colours, coloursCount, neighbor, nextColour)
	}
}
func fillAdjPlus(edges [][]int, adjPlus map[int][]int) {
	for _, edge := range edges {
		if _, exists := adjPlus[edge[0]]; !exists {
			adjPlus[edge[0]] = []int{}
		}
		adjPlus[edge[0]] = append(adjPlus[edge[0]], edge[1])
		if _, exists := adjPlus[edge[1]]; !exists {
			adjPlus[edge[1]] = []int{}
		}
		adjPlus[edge[1]] = append(adjPlus[edge[1]], edge[0])
	}
}
