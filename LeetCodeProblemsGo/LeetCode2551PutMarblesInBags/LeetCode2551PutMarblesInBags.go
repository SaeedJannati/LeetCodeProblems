package leetcode2551putmarblesinbags

import (
	"slices"
)

func putMarbles(weights []int, k int) int64 {
	if k == 1 {
		return 0
	}
	length := len(weights)
	if length == 1 {
		return 0
	}
	if k == length {
		return 0
	}
	for i := 0; i < length-1; i++ {
		weights[i] += weights[i+1]
	}
	weights[length-1] = 0
	slices.Sort(weights)
	var delta int64
	for i := 0; i < k-1; i++ {
		delta += int64(weights[length-1-i] - weights[i+1])
	}
	return delta
}
