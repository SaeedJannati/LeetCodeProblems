package main

func singleNumber(nums []int) []int {
	xorResult := 0
	length := len(nums)
	for i := 0; i < length; i++ {
		xorResult ^= nums[i]
	}
	firstBit := xorResult & (-xorResult)
	firstNum := 0
	for i := 0; i < length; i++ {
		if nums[i]&firstBit == 0 {
			continue
		}
		firstNum ^= nums[i]
	}
	secondNum := xorResult ^ firstNum
	return []int{firstNum, secondNum}
}
