package LeetCode3379TransformedArray

import "fmt"

func constructTransformedArray(nums []int) []int {
	length := len(nums)
	result := make([]int, 0, length)
	newIndex := 0
	for i := 0; i < length; i++ {
		newIndex = i + nums[i] + 100*length
		newIndex %= length
		result = append(result, nums[newIndex])
	}
	return result
}

func Calculate() {
	nums := []int{-10, -10}
	fmt.Println(constructTransformedArray(nums))

}
