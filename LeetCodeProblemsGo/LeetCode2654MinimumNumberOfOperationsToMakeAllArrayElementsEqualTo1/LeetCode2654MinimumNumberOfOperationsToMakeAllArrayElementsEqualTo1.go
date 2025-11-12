package LeetCode2654MinimumNumberOfOperationsToMakeAllArrayElementsEqualTo1

func getGcd(a, b int) int {
	if (a % b) == 0 {
		return b
	}
	return getGcd(b, a%b)
}
func calcGcd(nums []int, memoisation [][]int, start, end int) int {
	if memoisation[start][end] != 0 {
		return memoisation[start][end]
	}
	if start == end {
		memoisation[start][end] = nums[start]
		return memoisation[start][end]
	}
	if end-start == 1 {
		memoisation[start][end] = getGcd(nums[start], nums[end])
		return memoisation[start][end]
	}
	mid := (start + end) >> 1
	memoisation[start][end] = getGcd(calcGcd(nums, memoisation, start, mid), calcGcd(nums, memoisation, mid+1, end))
	return memoisation[start][end]
}
func minOperations(nums []int) int {
	length := len(nums)
	noneZeroLength := length
	for _, num := range nums {
		if num == 1 {
			noneZeroLength--
		}
	}
	if noneZeroLength != length {
		return noneZeroLength
	}
	memoisation := make([][]int, length)
	for i := 0; i < length; i++ {
		memoisation[i] = make([]int, length)
	}
	for i := 0; i < length; i++ {
		for j := 0; j < length-i; j++ {
			if calcGcd(nums, memoisation, j, j+i) == 1 {
				return i + length - 1
			}
		}
	}
	return -1
}
