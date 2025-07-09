package LeetCode1920BuildArrayFromPermutation

func buildArray(nums []int) []int {
	length := len(nums)
	for i := 0; i < length; i++ {
		nums[i] += length * (nums[nums[i]%length] % length)
	}
	for i := 0; i < length; i++ {
		nums[i] /= length
	}
	return nums
}
