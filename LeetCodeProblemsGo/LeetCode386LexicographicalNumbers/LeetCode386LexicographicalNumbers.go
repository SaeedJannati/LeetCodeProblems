package leetcode386lexicographicalnumbers

func lexicalOrder(n int) []int {
	result := []int{}
	for i := 1; i < 10; i++ {
		dfs(&result, i, n)
	}
	return result
}
func dfs(result *[]int, current int, n int) {
	if current > n {
		return
	}
	*result = append(*result, current)
	current *= 10
	next := 0
	for i := 0; i < 10; i++ {
		next = current + i
		if current > n {
			return
		}
		dfs(result, next, n)
	}
}
