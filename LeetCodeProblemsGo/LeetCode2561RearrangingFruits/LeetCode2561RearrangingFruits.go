package LeetCode2561RearrangingFruits

import (
	"math"
	"slices"
)

func minCost(basket1 []int, basket2 []int) int64 {
	firstMap := make(map[int]int)
	secondMap := make(map[int]int)
	sumMap := make(map[int]int)
	minValue := math.MaxInt
	for _, num := range basket1 {
		firstMap[num]++
		sumMap[num]++
		minValue = min(minValue, num)
	}
	for _, num := range basket2 {
		secondMap[num]++
		sumMap[num]++
		minValue = min(minValue, num)
	}
	totalChangesNeeded := 0
	valuesToCheck := []int{}
	for key, value := range sumMap {
		if value%2 == 1 {
			return -1
		}
		sumMap[key] = (int(math.Abs(float64(firstMap[key]-secondMap[key]))) >> 1)
		totalChangesNeeded += sumMap[key]
		valuesToCheck = append(valuesToCheck, key)
	}
	totalChangesNeeded >>= 1
	slices.Sort(valuesToCheck)
	var result int64 = 0
	var coefficient int64 = 0
	var delta int64 = 0
	changesMade := 0
	for _, num := range valuesToCheck {
		coefficient = int64(min(totalChangesNeeded-changesMade, sumMap[num]))
		if num > 2*minValue {
			delta = coefficient * int64(minValue) * 2
		} else {
			delta = coefficient * int64(num)
		}
		changesMade += int(coefficient)
		result += delta
	}
	return result
}
