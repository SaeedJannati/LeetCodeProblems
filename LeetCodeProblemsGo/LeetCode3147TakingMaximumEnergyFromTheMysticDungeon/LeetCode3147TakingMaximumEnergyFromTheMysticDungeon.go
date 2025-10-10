package LeetCode3147TakingMaximumEnergyFromTheMysticDungeon

import "math"

func maximumEnergy(energy []int, k int) int {
	length := len(energy)
	suffixSums := make([]int, length)
	maxEnergy := math.MinInt
	for i := length - 1; i >= 0; i-- {
		suffixSums[i] = energy[i]
		if i+k <= length-1 {
			suffixSums[i] += suffixSums[i+k]
		}
		maxEnergy = max(suffixSums[i], maxEnergy)
	}
	return maxEnergy
}
