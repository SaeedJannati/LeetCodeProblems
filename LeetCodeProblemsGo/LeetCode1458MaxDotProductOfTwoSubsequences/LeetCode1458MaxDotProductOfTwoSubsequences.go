package LeetCode1458MaxDotProductOfTwoSubsequences

import "math"

func calcDp(dp [][]int, nums1, nums2 []int, length1, length2, firstStart, secondStart int) int {
	if firstStart >= length1 {
		return math.MinInt32
	}
	if secondStart >= length2 {
		return math.MinInt32
	}
	if dp[firstStart][secondStart] != math.MinInt32 {
		return dp[firstStart][secondStart]
	}
	if firstStart == length1-1 && secondStart == length2-1 {
		dp[firstStart][secondStart] = nums1[firstStart] * nums2[secondStart]
		return dp[firstStart][secondStart]
	}
	delta := nums1[firstStart] * nums2[secondStart]
	result := delta
	if num := calcDp(dp, nums1, nums2, length1, length2, firstStart+1, secondStart+1); num > 0 {
		result = delta + num
	}

	result = max(result, calcDp(dp, nums1, nums2, length1, length2, firstStart, secondStart+1))
	result = max(result, calcDp(dp, nums1, nums2, length1, length2, firstStart+1, secondStart))
	dp[firstStart][secondStart] = result
	return result
}
func maxDotProduct(nums1 []int, nums2 []int) int {
	maxProduct := math.MinInt32
	length1 := len(nums1)
	length2 := len(nums2)
	maxLength := max(length1, length2)
	dp := make([][]int, maxLength)
	for i := 0; i < length1; i++ {
		dp[i] = make([]int, length2)
		for j := 0; j < length2; j++ {
			dp[i][j] = math.MinInt32

		}
	}
	for i := 0; i < length1; i++ {
		for j := i; j < length2; j++ {

			maxProduct = max(calcDp(dp, nums1, nums2, length1, length2, i, j), maxProduct)

		}
	}
	return maxProduct
}
