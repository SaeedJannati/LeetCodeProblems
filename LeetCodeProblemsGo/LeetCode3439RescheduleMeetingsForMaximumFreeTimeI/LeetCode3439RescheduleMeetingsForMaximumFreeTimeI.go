package LeetCode3439RescheduleMeetingsForMaximumFreeTimeI

func maxFreeTime(eventTime int, k int, startTime []int, endTime []int) int {
	length := len(startTime)
	delays := make([]int, length+1)
	lastEndTime := 0
	for i := 0; i < length; i++ {
		delays[i] = startTime[i] - lastEndTime
		lastEndTime = endTime[i]
	}
	delays[length] = eventTime - lastEndTime
	maxDelay := 0
	currentDelay := 0
	for i := 0; i <= k; i++ {
		currentDelay += delays[i]
	}
	maxDelay = currentDelay
	for i := k + 1; i <= length; i++ {
		currentDelay += delays[i] - delays[i-k-1]
		if currentDelay > maxDelay {
			maxDelay = currentDelay
		}
	}
	return maxDelay
}
