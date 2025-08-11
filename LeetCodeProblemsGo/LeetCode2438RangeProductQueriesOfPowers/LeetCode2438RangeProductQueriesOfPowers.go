package LeetCode2438RangeProductQueriesOfPowers

func moduloPow(power int, modulo int64) int {
	var current int64 = 1
	var currentPow int64 = 2
	pow := 1
	for pow <= power {
		if (pow & power) == pow {
			current = (currentPow * current) % modulo
			current %= modulo
		}
		pow <<= 1
		currentPow = (currentPow * currentPow) % modulo
	}
	return int(current)
}
func productQueries(n int, queries [][]int) []int {
	currentPow := 1
	pow := 0
	twoPows := []int{0}
	for currentPow <= n {
		if (n & currentPow) == currentPow {
			twoPows = append(twoPows, pow)
		}
		currentPow <<= 1
		pow++
	}
	var modulo int64 = 1e9 + 7
	for i := 1; i < len(twoPows); i++ {
		twoPows[i] += twoPows[i-1]
	}
	length := len(queries)
	result := make([]int, length)
	for i, query := range queries {
		delta := twoPows[query[1]+1] - twoPows[query[0]]
		result[i] = moduloPow(delta, modulo)
	}
	return result
}
