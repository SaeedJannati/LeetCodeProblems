package LeetCode3364MinimumPositiveSumSubarray

import (
	"fmt"
	"math"
)

func minimumSumSubarray(nums []int, l int, r int) int {
	var lengh int = len(nums)
	prefixSum := make([]int, lengh+1)

	for i := 1; i <= lengh; i++ {
		prefixSum[i] = prefixSum[i-1] + nums[i-1]
	}
	minSum := math.MaxInt32
	var currentSum int
	for i := 0; i < lengh; i++ {
		for j := l; j <= r; j++ {
			if j+i > lengh {
				break
			}
			currentSum = prefixSum[i+j] - prefixSum[i]
			if currentSum > 0 {
				minSum = int(math.Min(float64(minSum), float64(currentSum)))
			}
		}
	}
	if minSum == math.MaxInt32 {
		return -1
	}
	return minSum
}

func Calculate() {
	nums := []int{7, 3}
	l, r := 2, 2
	fmt.Println(minimumSumSubarray(nums, l, r))

}
