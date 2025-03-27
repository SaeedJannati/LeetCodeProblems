package leetcode2780minimumindexofavalidsplit

func minimumIndex(nums []int) int {
	dominantElement := nums[0]
	frequency := 1
	length := len(nums)
	if length == 1 {
		return -1
	}
	for i := 1; i < length; i++ {
		if nums[i] == dominantElement {
			frequency++
		} else {
			frequency--
		}
		if frequency == 0 {
			dominantElement = nums[i]
			frequency = 1
		}
	}
	dominantCount := 0
	for i := 0; i < length; i++ {
		if nums[i] == dominantElement {
			dominantCount++
		}
		nums[i] = dominantCount
	}
	for i := 0; i < length; i++ {
		if nums[i] <= (i+1)/2 {
			continue
		}
		if dominantCount-nums[i] <= (length-i-1)/2 {
			continue
		}
		return i
	}
	return -1
}
