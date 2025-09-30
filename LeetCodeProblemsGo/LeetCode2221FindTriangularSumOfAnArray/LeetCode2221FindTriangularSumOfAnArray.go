package LeetCode2221FindTriangularSumOfAnArray

func triangularSum(nums []int) int {
	length := len(nums)
	if length == 1 {
		return nums[0]
	}
	temp := 0
	for nums[1] != -1 {
		temp = nums[0]
		i := 0
		for i = 1; i < length; i++ {
			if nums[i] == -1 {
				break
			}
			nums[i-1] = (temp + nums[i]) % 10
			temp = nums[i]
		}
		nums[i-1] = -1
	}
	return nums[0]
}
