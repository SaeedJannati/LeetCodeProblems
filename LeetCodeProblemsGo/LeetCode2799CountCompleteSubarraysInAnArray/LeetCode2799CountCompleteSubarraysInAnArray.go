package LeetCode2799CountCompleteSubarraysInAnArray

import "fmt"

func Calculate() {
	nums := []int{1, 3, 1, 2, 2}
	fmt.Println(countCompleteSubarays(nums))
}
func countCompleteSubarays(nums []int) int {
	length := len(nums)
	numsMap := make(map[int]struct{})
	for _, num := range nums {
		numsMap[num] = struct{}{}
	}

	var result int = 0
	distinctCount := len(numsMap)
	for i := 0; i < length-distinctCount+1; i++ {
		numsMap = make(map[int]struct{})
		for j := i; j < length; j++ {
			numsMap[nums[j]] = struct{}{}
			if len(numsMap) < distinctCount {
				continue
			}
			result += length - j
			break
		}
	}
	return result
}
