package LeetCode3350AdjacentIncreasingSubarraysDetectionII

func maxIncreasingSubarrays(nums []int) int {
	length := len(nums)
	previousStreak := 0
	currentStreak := 1
	maxK := 0
	for i := 1; i < length; i++ {
		if nums[i] <= nums[i-1] {
			maxK = max(maxK, currentStreak/2)
			maxK = max(maxK, min(currentStreak, previousStreak))
			previousStreak = currentStreak
			currentStreak = 1
			continue
		}
		currentStreak++
	}
	maxK = max(maxK, currentStreak/2)
	maxK = max(maxK, min(currentStreak, previousStreak))
	return maxK
}
