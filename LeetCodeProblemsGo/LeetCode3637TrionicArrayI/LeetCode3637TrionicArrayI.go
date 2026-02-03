package LeetCode3637TrionicArrayI

func isTrionic(nums []int) bool {
	slopes := []int{}
	previous := nums[0]
	length := len(nums)
	slope := 0
	delta := 0
	for i := 1; i < length; i++ {
		delta = nums[i] - previous
		previous = nums[i]
		if delta == 0 {
			return false
		}
		if len(slopes) == 0 {
			if delta < 0 {
				return false
			}
			slopes = append(slopes, 1)
			continue
		}
		if delta > 0 {
			slope = 1
		} else {
			slope = -1
		}
		if slope*slopes[len(slopes)-1] > 0 {
			continue
		}
		slopes = append(slopes, slope)
		if len(slopes) > 3 {
			return false
		}
	}
	if len(slopes) != 3 {
		return false
	}
	return true
}
