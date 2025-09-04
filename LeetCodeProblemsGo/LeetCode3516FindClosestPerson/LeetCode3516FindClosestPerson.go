package LeetCode3516FindClosestPerson

import "math"

func findClosest(x int, y int, z int) int {
	delta := math.Abs(float64(x-z)) - math.Abs(float64(y-z))
	if delta > 0 {
		return 2
	}
	if delta < 0 {
		return 1
	}
	return 0
}
