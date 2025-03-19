package main

func minOperations(nums []int) int {
	length := len(nums)
	operationCount := 0
	for i := 0; i < length-2; i++ {
		if nums[i] == 0 {
			operationCount++
			nums[i+1] ^= 1
			nums[i+2] ^= 1
		}
	}
	if nums[length-2]+nums[length-1] < 2 {
		return -1
	}
	return operationCount
}
