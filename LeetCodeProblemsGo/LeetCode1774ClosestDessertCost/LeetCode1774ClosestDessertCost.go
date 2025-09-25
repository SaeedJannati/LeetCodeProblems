package LeetCode1774ClosestDessertCost

import (
	"math"
	"slices"
)

func closestCost(baseCosts []int, toppingCosts []int, target int) int {
	maxPrice := 0
	maxPrice = slices.Max(baseCosts)
	for _, topping := range toppingCosts {
		maxPrice += topping * 2
	}
	canMake := make([]bool, maxPrice+1)
	for _, base := range baseCosts {
		canMake[base] = true
	}
	for _, topping := range toppingCosts {
		for i := 0; i < 2; i++ {
			for j := maxPrice; j >= topping; j-- {
				if canMake[j-topping] {
					canMake[j] = true
				}
			}
		}
	}
	closesetDelta := math.MaxInt32
	closest := 0
	var delta int
	for i := 0; i <= maxPrice; i++ {
		if !canMake[i] {
			continue
		}
		delta = i - target
		if delta < 0 {
			delta *= -1
		}
		if closesetDelta > delta {
			closesetDelta = delta
			closest = i
		}
	}
	return closest
}
