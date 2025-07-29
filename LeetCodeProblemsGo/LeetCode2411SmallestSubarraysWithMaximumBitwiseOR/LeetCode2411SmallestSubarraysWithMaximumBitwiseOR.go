package LeetCode2411SmallestSubarraysWithMaximumBitwiseOR

func smallestSubarrays(nums []int) []int {
	length := len(nums)
	lastSeen := make([]int, 32)
	for i := 0; i < 32; i++ {
		lastSeen[i] = -1
	}
	result := make([]int, length)
	for i := length - 1; i >= 0; i-- {
		for j := 0; j < 32; j++ {
			if (nums[i]>>j)&1 == 1 {
				lastSeen[j] = i
			}
		}
		maxIndex := i
		for j := 0; j < 32; j++ {
			maxIndex = max(maxIndex, lastSeen[j])
		}
		result[i] = maxIndex - i + 1
	}
	return result
}
