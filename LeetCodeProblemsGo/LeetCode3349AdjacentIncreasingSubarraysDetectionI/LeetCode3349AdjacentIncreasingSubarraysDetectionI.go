package LeetCode3349AdjacentIncreasingSubarraysDetectionI

func hasIncreasingSubarrays(nums []int, k int) bool {
	length := len(nums)
	previousStreak := 0
	currentStreak := 1
	for i := 1; i < length; i++ {
		if nums[i] <= nums[i-1] {
			if currentStreak >= 2*k {
				return true
			}
			if currentStreak >= k {
				if previousStreak >= k {
					return true
				}
			}
			previousStreak = currentStreak
			currentStreak = 1
			continue
		}
		currentStreak++
	}
	if currentStreak >= 2*k {
		return true
	}
	if currentStreak >= k {
		if previousStreak >= k {
			return true
		}
	}
	return false
}
