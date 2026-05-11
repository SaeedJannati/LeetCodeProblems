package LeetCode3259MaximumEnergyBoostFromTwoDrinks

func maxEnergyBoost(energyDrinkA []int, energyDrinkB []int) int64 {
	length := len(energyDrinkA)
	dpA := []int64{int64(energyDrinkA[0]), int64(energyDrinkA[1]) + int64(energyDrinkA[0]), 0}
	dpB := []int64{int64(energyDrinkB[0]), int64(energyDrinkB[1]) + int64(energyDrinkB[0]), 0}
	for i := 2; i < length; i++ {
		dpA[2] = max(dpA[1], dpB[0]) + int64(energyDrinkA[i])
		dpB[2] = max(dpB[1], dpA[0]) + int64(energyDrinkB[i])
		dpA[0], dpA[1] = dpA[1], dpA[2]
		dpB[0], dpB[1] = dpB[1], dpB[2]
	}
	return max(dpA[1], dpB[1])
}
