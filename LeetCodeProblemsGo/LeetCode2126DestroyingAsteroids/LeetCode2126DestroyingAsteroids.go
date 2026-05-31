package LeetCode2126DestroyingAsteroids

import "sort"

func asteroidsDestroyed(mass int, asteroids []int) bool {
	sort.Ints(asteroids)
	var aggregatedMass int64 = int64(mass)
	for _, asteroid := range asteroids {
		if aggregatedMass < int64(asteroid) {
			return false
		}
		aggregatedMass += int64(asteroid)
	}
	return true
}
