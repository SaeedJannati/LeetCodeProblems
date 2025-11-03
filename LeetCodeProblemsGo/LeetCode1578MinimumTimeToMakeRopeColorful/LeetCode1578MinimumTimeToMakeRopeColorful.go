package LeetCode1578MinimumTimeToMakeRopeColorful

func minCost(colors string, neededTime []int) int {
	previousColor := byte(0)
	totalTime := 0
	maxTime := 0
	totalBatchTime := 0
	length := len(colors)
	for i := 0; i < length; i++ {
		if colors[i] == previousColor {
			maxTime = max(maxTime, neededTime[i])
			totalBatchTime += neededTime[i]
			continue
		}
		if totalBatchTime > maxTime {
			totalTime += totalBatchTime - maxTime
		}
		previousColor = colors[i]
		maxTime = neededTime[i]
		totalBatchTime = neededTime[i]
	}
	if totalBatchTime > maxTime {
		totalTime += totalBatchTime - maxTime
	}
	return totalTime
}
