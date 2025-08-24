package LeetCode1493LongestSubarrayOf1sAfterDeletingOneElement

func longestSubarray(nums []int) int {
	lastZeroIndex := -1
	length := len(nums)
	firstPointer := 0
	maxLength := 0
	currentLength := 0
	for i := 0; i < length; i++ {
		if nums[i] != 0 {
			continue
		}
		if lastZeroIndex == -1 {
			lastZeroIndex = i
			continue
		}
		currentLength = i - firstPointer - 1
		maxLength = max(currentLength, maxLength)
		firstPointer = lastZeroIndex + 1
		lastZeroIndex = i
	}
	currentLength = length - firstPointer - 1
	maxLength = max(currentLength, maxLength)
	return maxLength
}
