package LeetCode2141MaximumRunningTimeOfNComputers

func maxRunTime(n int, batteries []int) int64 {
	var totalPower int64
	for _, battery := range batteries {
		totalPower += int64(battery)
	}
	var minTarget int64 = 1
	maxTarget := totalPower / int64(n)
	var midTarget int64
	var target int64 = 0
	var availablePower int64
	for minTarget <= maxTarget {
		midTarget = (maxTarget + minTarget) >> 1
		availablePower = 0
		for _, battery := range batteries {
			availablePower += min(midTarget, int64(battery))
		}
		if availablePower >= int64(n)*midTarget {
			target = max(target, midTarget)
			minTarget = midTarget + 1
			continue
		}
		maxTarget = midTarget - 1
	}
	return target

}
