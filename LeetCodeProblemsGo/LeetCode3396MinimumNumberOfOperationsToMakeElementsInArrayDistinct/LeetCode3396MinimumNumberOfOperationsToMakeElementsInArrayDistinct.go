package LeetCode3396MinimumNumberOfOperationsToMakeElementsInArrayDistinct

func minimumOperations(nums []int) int {
	length := len(nums)
	distinctNums := make(map[int]interface{})
	for i := length - 1; i >= 0; i-- {
		if _, exists := distinctNums[nums[i]]; exists {
			delta := 0
			if (i+1)%3 != 0 {
				delta = 1
			}
			return (i+1)/3 + delta
		}
		distinctNums[nums[i]] = nil
	}
	return 0
}
