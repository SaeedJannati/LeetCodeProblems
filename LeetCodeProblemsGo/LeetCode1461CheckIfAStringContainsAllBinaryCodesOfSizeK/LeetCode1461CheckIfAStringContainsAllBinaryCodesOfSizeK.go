package LeetCode1461CheckIfAStringContainsAllBinaryCodesOfSizeK

import "fmt"

func hasAllCodes(s string, k int) bool {
	length := len(s)
	if length < k {
		return false
	}
	nums := make(map[int]any)
	candidate := 0
	for i := 0; i < k; i++ {
		candidate = candidate << 1
		if s[i] == '1' {
			candidate++
		}
	}
	nums[candidate] = nil
	for i := k; i < length; i++ {
		candidate &= ^(1 << (k - 1))
		candidate <<= 1
		if s[i] == '1' {
			candidate++
		}
		nums[candidate] = nil
	}
	return len(nums) == 1<<k
}
func Calculate() {
	k := 2
	s := "00110110"
	fmt.Println(hasAllCodes(s, k))
}
