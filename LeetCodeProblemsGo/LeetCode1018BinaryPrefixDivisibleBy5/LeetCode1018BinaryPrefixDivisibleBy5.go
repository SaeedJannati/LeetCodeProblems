package LeetCode1018BinaryPrefixDivisibleBy5

func prefixesDivBy5(nums []int) []bool {
	length := len(nums)
	mod := 0
	result := make([]bool, length)
	for i := 0; i < length; i++ {
		mod = (mod << 1) % 5
		mod += nums[i]
		mod %= 5
		result[i] = mod == 0
	}
	return result
}
