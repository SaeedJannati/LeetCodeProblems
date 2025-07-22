package LeetCode1695MaximumErasureValue

//prefix sum solution O(n) time and O(n) space
func maximumUniqueSubarray(nums []int) int {
	sum := 0
	maxSum := 0
	firstPointer := 0
	secondPointer := 0
	length := len(nums)
	prefixSum := make([]int, length)
	numsMap := make(map[int]int)
	for secondPointer < length {
		if _, exists := numsMap[nums[secondPointer]]; exists {
			if numsMap[nums[secondPointer]] >= firstPointer {
				firstPointer = numsMap[nums[secondPointer]] + 1
			}
		}
		if secondPointer == 0 {
			prefixSum[secondPointer] = nums[secondPointer]
		} else {
			prefixSum[secondPointer] = prefixSum[secondPointer-1] + nums[secondPointer]
		}
		numsMap[nums[secondPointer]] = secondPointer
		sum = prefixSum[secondPointer] - prefixSum[firstPointer] + nums[firstPointer]
		maxSum = max(maxSum, sum)
		secondPointer++
	}
	return maxSum
}

// without prefix sum still O(n) and uses less memory simpler code too
// func maximumUniqueSubarray(nums []int) int {
//     sum := 0
// 	maxSum := 0
// 	firstPointer := 0
// 	secondPointer := 0
// 	length := len(nums)
// 	numsMap := make(map[int]int)
// 	for secondPointer < length {
// 		if _, exists := numsMap[nums[secondPointer]]; exists {
// 			for i := firstPointer; i <= numsMap[nums[secondPointer]]; i++ {
// 				sum -= nums[i]
// 				delete(numsMap, nums[i])
// 				firstPointer++
// 			}
// 		}

// 		numsMap[nums[secondPointer]] = secondPointer
// 		sum += nums[secondPointer]
// 			maxSum = max(maxSum, sum)
// 		secondPointer++
// 	}
// 	return maxSum
// }
