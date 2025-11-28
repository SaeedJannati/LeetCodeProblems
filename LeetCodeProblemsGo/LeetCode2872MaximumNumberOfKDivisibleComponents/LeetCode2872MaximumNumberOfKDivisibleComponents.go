package LeetCode2872MaximumNumberOfKDivisibleComponents

func maxKDivisibleComponents(n int, edges [][]int, values []int, k int) int {
	visited := make([]bool, n)
	adjPlus := make(map[int][]int)
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
	result := 1
	visited[0] = true
	dfs(values, k, visited, adjPlus, &result, 0)
	return result
}
func dfs(values []int, k int, visited []bool, adjPlus map[int][]int, result *int, index int) int {
	visited[index] = true
	branchMod := 0
	mod := values[index] % k
	for _, neighbour := range adjPlus[index] {
		if visited[neighbour] {
			continue
		}
		visited[neighbour] = true
		branchMod = dfs(values, k, visited, adjPlus, result, neighbour)
		if branchMod == 0 {
			(*result)++
			continue
		}
		mod += branchMod
		mod %= k
	}
	return mod
}
