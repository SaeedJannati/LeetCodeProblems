package LeetCode3363FindTheMaximumNumberOfFruitsCollected

func maxCollectedFruits(fruits [][]int) int {
	length := len(fruits)
	result := 0
	visited := make([][]bool, length)
	dp := make([][]int, length)
	for i := 0; i < length; i++ {
		visited[i] = make([]bool, length)
		dp[i] = make([]int, length)
		result += fruits[i][i]
		fruits[i][i] = 0
	}
	directions := [][]int{{1, 0}, {1, -1}, {1, 1}}
	result += calculatePlayerPath(fruits, dp, directions, visited, []int{0, length - 1}, true, length)
	for i := 0; i < length; i++ {
		dp[i][i] = 0
		visited[i][i] = false
	}
	directions = [][]int{{1, 1}, {0, 1}, {-1, 1}}
	result += calculatePlayerPath(fruits, dp, directions, visited, []int{length - 1, 0}, false, length)
	return result
}
func calculatePlayerPath(fruits [][]int, dp [][]int, directions [][]int, visited [][]bool, startPos []int, shouldWidthBeGreater bool, length int) int {
	currentLayer := [][]int{{startPos[0], startPos[1]}}
	nextLayer := [][]int{}
	visited[startPos[0]][startPos[1]] = true
	dp[startPos[0]][startPos[1]] = fruits[startPos[0]][startPos[1]]
	newHeight := 0
	newWidth := 0
	potentialFruits := 0
	for i := 1; i < length; i++ {
		for _, coord := range currentLayer {
			for _, dir := range directions {
				newHeight = coord[0] + dir[0]
				if newHeight < 0 || newHeight > length-1 {
					continue
				}
				newWidth = coord[1] + dir[1]
				if newWidth < 0 || newWidth > length-1 {
					continue
				}
				if shouldWidthBeGreater {
					if newHeight > newWidth {
						continue
					}
				}
				if !shouldWidthBeGreater {
					if newHeight < newWidth {
						continue
					}
				}
				potentialFruits = dp[coord[0]][coord[1]] + fruits[newHeight][newWidth]
				if potentialFruits > dp[newHeight][newWidth] {
					dp[newHeight][newWidth] = potentialFruits
				}
				if visited[newHeight][newWidth] {
					continue
				}
				visited[newHeight][newWidth] = true
				nextLayer = append(nextLayer, []int{newHeight, newWidth})
			}
		}
		currentLayer = [][]int{}
		currentLayer = append(currentLayer, nextLayer...)
		nextLayer = [][]int{}
	}
	return dp[length-1][length-1]
}
