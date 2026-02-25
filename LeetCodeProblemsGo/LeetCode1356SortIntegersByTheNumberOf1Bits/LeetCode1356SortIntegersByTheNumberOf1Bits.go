package LeetCode1356SortIntegersByTheNumberOf1Bits

import "slices"

func sortByBits(arr []int) []int {
	oneBitCounts := make([][]int, 15)
	for i := 0; i < 15; i++ {
		oneBitCounts[i] = make([]int, 0)
	}
	for _, num := range arr {
		count := getOneBitsCount(num)
		oneBitCounts[count] = append(oneBitCounts[count], num)
	}
	for _, counts := range oneBitCounts {
		slices.Sort(counts)
	}
	result := make([]int, 0, len(arr))
	for _, nums := range oneBitCounts {
		result = append(result, nums...)
	}
	return result
}
func getOneBitsCount(num int) (count int) {
	for num > 0 {
		if num&1 == 1 {
			count++
		}
		num >>= 1
	}
	return
}
