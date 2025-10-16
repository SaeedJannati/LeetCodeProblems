package LeetCode2598SmallestMissingNonnegativeIntegerAfterOperations

import "math"

func findSmallestInteger(nums []int, value int) int {
	length := len(nums)
	if value == 1 {
		return length
	}
	modMap := make(map[int]int)
	for i := 0; i < value; i++ {
		modMap[i] = 0
	}
	mod := 0
	for _, num := range nums {
		mod = num % value
		if mod < 0 {
			mod += value
		}
		modMap[mod]++
	}
	minMod := 0
	minOccurrence := math.MaxInt32

	for numMod, numOccurrence := range modMap {
		if numOccurrence < minOccurrence {
			minOccurrence = numOccurrence
			minMod = numMod
			continue
		}
		if numOccurrence == minOccurrence {
			minMod = min(minMod, numMod)
		}
	}
	return minOccurrence*value + minMod

}
