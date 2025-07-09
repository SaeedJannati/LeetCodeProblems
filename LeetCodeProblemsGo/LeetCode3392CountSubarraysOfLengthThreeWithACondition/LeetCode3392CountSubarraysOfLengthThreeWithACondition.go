package LeetCode3392CountSubarraysOfLengthThreeWithACondition

func countSubarrays(nums []int) int {
	length := len(nums)
	if length < 3 {
		return 0
	}
	result := 0
	for i := 1; i < length-1; i++ {
		if nums[i]%2 != 0 {
			continue
		}
		if nums[i-1]+nums[i+1] != nums[i]/2 {
			continue
		}
		result++
	}
	return result
}
