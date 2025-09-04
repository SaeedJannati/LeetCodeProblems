package LeetCode475Heaters

import (
	"math"
	"slices"
)

func findRadius(houses []int, heaters []int) int {
	slices.Sort(heaters)
	length := len(heaters)
	maxDistance := math.MinInt32
	var minDistance int
	for _, house := range houses {
		minDistance = math.MaxInt32
		begin := 0
		end := length - 1
		var mid int
		for begin <= end {
			mid = (end + begin) >> 1
			if house == heaters[mid] {
				break
			}
			if house < heaters[mid] {
				end = mid - 1
				continue
			}
			begin = mid + 1
		}
		if house == heaters[mid] {
			minDistance = 0
		} else {
			minDistance = min(minDistance, int(math.Abs(float64(house-heaters[mid]))))
			if mid > 0 {
				minDistance = min(minDistance, int(math.Abs(float64(house-heaters[mid-1]))))
			}
			if mid < length-1 {
				minDistance = min(minDistance, int(math.Abs(float64(house-heaters[mid+1]))))
			}
		}
		maxDistance = max(minDistance, maxDistance)
	}
	return maxDistance
}
