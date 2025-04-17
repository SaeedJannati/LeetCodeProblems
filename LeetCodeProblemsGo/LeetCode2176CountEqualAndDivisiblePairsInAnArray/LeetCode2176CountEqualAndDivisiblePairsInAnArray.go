package LeetCode2176CountEqualAndDivisiblePairsInAnArray

func countPairs(nums []int, k int) int {
	length := len(nums)
	result := 0
	for i := 0; i < length-1; i++ {
		for j := i + 1; j < length; j++ {
			if nums[i] != nums[j] {
				continue
			}
			if (i*j)%k != 0 {
				continue
			}
			result++
		}
	}
	return result
}
