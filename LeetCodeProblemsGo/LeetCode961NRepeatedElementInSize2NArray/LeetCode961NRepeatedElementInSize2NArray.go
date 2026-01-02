package LeetCode961NRepeatedElementInSize2NArray

func repeatedNTimes(nums []int) int {
	length := len(nums)
	if nums[0] == nums[1] || nums[0] == nums[2] {
		return nums[0]
	}
	if nums[1] == nums[2] {
		return nums[1]
	}
	candidate, count := 0, 0
	for i := 3; i < length; i++ {
		if count == 0 {
			candidate = nums[i]
			count = 1
			continue
		} else if nums[i] == candidate {
			count++
		} else {
			count--
		}
	}
	return candidate
}
