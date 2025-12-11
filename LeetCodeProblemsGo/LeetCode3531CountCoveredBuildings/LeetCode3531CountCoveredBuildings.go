package LeetCode3531CountCoveredBuildings

func countCoveredBuildings(n int, buildings [][]int) int {
	minPerRow := make([]int, n+1)
	maxPerRow := make([]int, n+1)
	minPerCol := make([]int, n+1)
	maxPerCol := make([]int, n+1)
	for i := 1; i <= n; i++ {
		minPerCol[i] = n + 1
		minPerRow[i] = n + 1
	}
	for _, building := range buildings {
		minPerRow[building[0]] = min(minPerRow[building[0]], building[1])
		maxPerRow[building[0]] = max(maxPerRow[building[0]], building[1])

		minPerCol[building[1]] = min(minPerCol[building[1]], building[0])
		maxPerCol[building[1]] = max(maxPerCol[building[1]], building[0])
	}
	result := 0
	for _, building := range buildings {
		if building[0] > minPerCol[building[1]] &&
			building[0] < maxPerCol[building[1]] &&
			building[1] > minPerRow[building[0]] &&
			building[1] < maxPerRow[building[0]] {
			result++
		}
	}
	return result
}
