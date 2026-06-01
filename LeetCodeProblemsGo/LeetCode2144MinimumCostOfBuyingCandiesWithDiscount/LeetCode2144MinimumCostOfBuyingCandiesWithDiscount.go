package LeetCode2144MinimumCostOfBuyingCandiesWithDiscount

import "sort"

func minimumCost(cost []int) int {
	sort.Ints(cost)
	index := len(cost) - 1
	spent := 0
	for index >= 0 {
		for i := 0; i < 2; i++ {
			spent += cost[index]
			index--
			if index < 0 {
				break
			}
		}
		index--
	}
	return spent
}
