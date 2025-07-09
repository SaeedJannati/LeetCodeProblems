package LeetCode440KthSmallestInLexicographicalOrder

import "fmt"

func findKthNumber(n int, k int) int {
	current := 1
	steps := 0
	k--
	for k > 0 {
		steps = getNumCountInBetween(int64(current), int64(current+1), int64(n))
		if steps <= k {
			current++
			k -= steps
		} else {
			current *= 10
			k--
		}
	}
	return current
}
func getNumCountInBetween(first, second, n int64) int {
	result := 0
	var minValue int64
	for first <= n {
		minValue = second
		if n < minValue {
			minValue = n
		}
		result += int(minValue - first)
		first *= 10
		second *= 10
	}
	return result
}

func Calculate() {
	n := 17
	k := 2
	fmt.Println(findKthNumber(n, k))
}
