package LeetCode3542MinimumOperationsToConvertAllElementsToZero

func minOperations(nums []int) int {
	operations := 0
	monotoniqueMaxStack := []int{}
	for _, num := range nums {
		for (len(monotoniqueMaxStack) > 0) &&
			monotoniqueMaxStack[len(monotoniqueMaxStack)-1] > num {
			monotoniqueMaxStack = monotoniqueMaxStack[:len(monotoniqueMaxStack)-1]
		}
		if num == 0 {
			continue
		}
		if len(monotoniqueMaxStack) == 0 || monotoniqueMaxStack[len(monotoniqueMaxStack)-1] < num {
			monotoniqueMaxStack = append(monotoniqueMaxStack, num)
			operations++
		}

	}

	return operations
}
