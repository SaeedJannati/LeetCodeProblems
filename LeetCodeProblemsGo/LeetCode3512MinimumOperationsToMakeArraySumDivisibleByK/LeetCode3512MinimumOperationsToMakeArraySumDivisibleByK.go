package LeetCode3512MinimumOperationsToMakeArraySumDivisibleByK

func minOperations(nums []int, k int) int {
	sum := 0
	for _, num := range nums {
		sum += num
	}
	return sum % k
}
