package LeetCode1695MaximumErasureValue

func maximumUniqueSubarray(nums []int) int {
	sum := 0
	maxSum := 0
	firstPointer := 0
	secondPointer := 0
	length := len(nums)
	numsMap := make(map[int]int)
	for secondPointer < length {
		if _, exists := numsMap[nums[secondPointer]]; exists {
			for i := firstPointer; i <= numsMap[nums[secondPointer]]; i++ {
				sum -= nums[i]
				delete(numsMap, nums[i])
				firstPointer++
			}
		}

		numsMap[nums[secondPointer]] = secondPointer
		sum += nums[secondPointer]
		maxSum = max(maxSum, sum)
		secondPointer++
	}
	return maxSum
}
