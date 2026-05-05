package LeetCode797AllPathsFromSourceToTarget

func dfs(graph [][]int, length int, visited []bool, result *[][]int, path *[]int, node int) {
	if node == length-1 {
		newPath := make([]int, len(*path))
		copy(newPath, *path)
		*result = append(*result, newPath)
		return
	}
	for _, neighbour := range graph[node] {
		if visited[neighbour] {
			continue
		}
		visited[neighbour] = true
		*path = append(*path, neighbour)
		dfs(graph, length, visited, result, path, neighbour)
		*path = (*path)[:len(*path)-1]
		visited[neighbour] = false
	}
}

func allPathsSourceTarget(graph [][]int) [][]int {
	length := len(graph)
	visited := make([]bool, length)
	visited[0] = true
	path := []int{0}
	result := [][]int{}
	dfs(graph, length, visited, &result, &path, 0)
	return result
}
