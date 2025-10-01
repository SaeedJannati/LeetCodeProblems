package LeetCode1518WaterBottles

func numWaterBottles(numBottles int, numExchange int) int {
	tempBottlesCount := 0
	emptyBottles := 0
	drankBottles := 0
	for numBottles+emptyBottles >= numExchange {
		tempBottlesCount = numBottles
		emptyBottles += numBottles
		numBottles = emptyBottles / numExchange
		emptyBottles = emptyBottles % numExchange
		drankBottles += tempBottlesCount
	}
	return drankBottles + numBottles
}
