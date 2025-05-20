package main

func isZeroArray(nums []int, queries [][]int) bool {
	length := len(nums)
	prefixSum := make([]int, length+1)
	for _, pair := range queries {
		prefixSum[pair[0]]++
		prefixSum[pair[1]+1]--
	}
	if nums[0] > prefixSum[0] {
		return false
	}
	for i := 1; i < length; i++ {
		prefixSum[i] += prefixSum[i-1]
		if nums[i]-prefixSum[i] > 0 {
			return false
		}
	}
	return true

}
