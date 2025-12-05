package LeetCode3432CountPartitionsWithEvenSumDifference

func countPartitions(nums []int) int {
	length := len(nums)
	prefixSums := make([]bool, length+1)
	for i := 0; i <= length; i++ {
		prefixSums[i+1] = prefixSums[i] != (nums[i]%2 == 1)
	}
	result := 0
	modBefore := false
	modAfter := false
	for i := 0; i < length-1; i++ {
		modAfter = prefixSums[length] != prefixSums[i]
		modBefore = prefixSums[length] != modAfter
		if modBefore == modAfter {
			result++
		}
	}
	return result
}
