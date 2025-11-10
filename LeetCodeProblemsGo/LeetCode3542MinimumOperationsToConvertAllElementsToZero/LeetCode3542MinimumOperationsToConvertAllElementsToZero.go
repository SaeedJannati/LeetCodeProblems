package LeetCode3542MinimumOperationsToConvertAllElementsToZero

func minOperations(nums []int) int {
	length := len(nums)
	rightRange := make([]int, length)
	for i := 0; i < length; i++ {
		rightRange[i] = length - 1
	}
	monotoniqueMaxStack := [][]int{}
	for i := length - 1; i >= 0; i-- {
		for (len(monotoniqueMaxStack) > 0) &&
			monotoniqueMaxStack[len(monotoniqueMaxStack)-1][0] >= nums[i] {
			monotoniqueMaxStack = monotoniqueMaxStack[:len(monotoniqueMaxStack)-1]
		}
		if len(monotoniqueMaxStack) > 0 {
			rightRange[i] = monotoniqueMaxStack[len(monotoniqueMaxStack)-1][1] - 1
		}
		monotoniqueMaxStack = append(monotoniqueMaxStack, []int{nums[i], i})
	}
	operationRange := make(map[int]int)
	operations := 0
	for i := 0; i < length; i++ {
		if nums[i] == 0 {
			continue
		}
		if index, exists := operationRange[nums[i]]; exists {
			if index >= rightRange[i] {
				continue
			}
		}
		operations++
		operationRange[nums[i]] = rightRange[i]
	}
	return operations
}
