package LeetCode3100WaterBottlesII

import "math"

func maxBottlesDrunk(numBottles int, numExchange int) int {
	b := 2*numExchange - 3
	c := -2 * numBottles
	delta := float64(b*b - 4*c)
	t := int(math.Ceil((-float64(b) + math.Sqrt(delta)) / 2.0))
	return numBottles + t - 1
}
