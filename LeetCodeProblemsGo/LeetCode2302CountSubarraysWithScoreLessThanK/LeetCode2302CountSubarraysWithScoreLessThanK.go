package LeetCode2302CountSubarraysWithScoreLessThanK

func countSubarrays(nums []int, k int64) int64 {
	length := len(nums)
	var result int64
	prefixSums := make([]int64, length)
	prefixSums[0] = int64(nums[0])
	var index int
	for i := 1; i < length; i++ {
		prefixSums[i] = prefixSums[i-1] + int64(nums[i])
	}
	for i := 0; i < length; i++ {
		index = findIndex(prefixSums, nums[i], length, i, k)
		if index == -1 {
			continue
		}
		result += int64(index - i + 1)
	}
	return result

}
func findIndex(prefixSums []int64, num int, length int, index int, k int64) int {
	begin := index
	end := length - 1
	var mid int
	result := -1
	var mult int64
	for begin <= end {
		mid = (begin + end) / 2
		mult = (prefixSums[mid] - prefixSums[index] + int64(num)) * int64(mid-index+1)
		if mult < k {
			if mid > result {
				result = mid
			}
			begin = mid + 1
			continue
		}
		end = mid - 1
	}
	return result
}
