package LeetCode3190FindMinimumOperationsToMakeAllElementsDivisibleByThree

func minimumOperations(nums []int) int {
	operationsCount := 0
	for _, num := range nums {
		if num%3 != 0 {
			operationsCount++
		}
	}
	return operationsCount
}
