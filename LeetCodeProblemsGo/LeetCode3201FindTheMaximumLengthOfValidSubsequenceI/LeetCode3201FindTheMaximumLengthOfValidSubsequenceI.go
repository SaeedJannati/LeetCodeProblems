package LeetCode3201FindTheMaximumLengthOfValidSubsequenceI

func maximumLength(nums []int) int {
	length := len(nums)
	oddCount := 0
	evenCount := 0
	for _, num := range nums {
		if num%2 == 0 {
			evenCount++
		} else {
			oddCount++
		}
	}
	result := evenCount
	if oddCount > evenCount {
		result = oddCount
	}
	modulo := nums[0] % 2
	modulo = 1 - modulo
	alternateCount := 1
	for i := 1; i < length; i++ {
		if nums[i]%2 == modulo {
			modulo = 1 - modulo
			alternateCount++
		}
	}
	if alternateCount > result {
		result = alternateCount
	}
	return result
}
