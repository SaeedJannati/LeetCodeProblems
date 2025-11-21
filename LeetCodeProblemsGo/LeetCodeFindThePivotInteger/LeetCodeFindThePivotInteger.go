package LeetCodeFindThePivotInteger

import "math"

func PivotInteger(n int) int {
	x := math.Sqrt(float64(n*n+n) / 2)
	if x == float64(int(x)) {
		return int(x)
	}
	return -1
}
