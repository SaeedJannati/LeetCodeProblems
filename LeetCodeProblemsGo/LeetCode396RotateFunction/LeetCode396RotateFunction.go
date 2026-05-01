package leetcode396rotatefunction

func maxRotateFunction(nums []int) int {
	n := len(nums)
	elementsSum := nums[0]
	currentSum := 0
	for i := 1; i < n; i++ {
		currentSum += i * nums[i]
		elementsSum += nums[i]
	}
	maxSum := currentSum
	for i := 1; i < n; i++ {
		currentSum += elementsSum - n*nums[n-i]
		maxSum = max(maxSum, currentSum)
	}
	return maxSum

}
