package LeetCode1863SumOfAllSubsetXORTotals

func subsetXORSum(nums []int) int {
	sum := 0
	length := len(nums)
	backtrack(0, nums, 0, &sum, length)
	return sum
}
func backtrack(index int, nums []int, currentXor int, sum *int, length int) {
	temp := 0
	for i := index; i < length; i++ {
		temp = currentXor ^ nums[i]
		*sum += temp
		backtrack(i+1, nums, temp, sum, length)
	}
}
