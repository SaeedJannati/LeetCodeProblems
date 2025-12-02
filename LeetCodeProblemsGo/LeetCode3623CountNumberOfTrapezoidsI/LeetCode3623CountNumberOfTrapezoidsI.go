package LeetCode3623CountNumberOfTrapezoidsI

func countTrapezoids(points [][]int) int {
	yMap := make(map[int]int)
	for _, point := range points {
		yMap[point[1]]++
	}
	var sum int64 = 0
	var result int64 = 0
	var mod int64 = 1e9 + 7
	var delta int64
	for _, value := range yMap {
		delta = int64(value)
		delta *= int64(value) - 1
		delta >>= 1
		delta %= mod
		result += (sum * delta)
		result %= mod
		sum += delta
		sum %= mod
	}
	return int(result)
}
