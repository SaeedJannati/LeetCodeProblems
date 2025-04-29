package LeetCode2962CountSubarraysWhereMaxElementAppearsAtLeastKTimes

func countSubarrays(nums []int, k int) int64 {
	max := 0
	maxOccurrence := 0
	for _, num := range nums {
		if num > max {
			max = num
			maxOccurrence = 1
		} else if num == max {
			maxOccurrence++
		}
	}
	if maxOccurrence < k {
		return 0
	}
	var result int64 = 0
	secondPointer := -1
	length := len(nums)
	maxCount := 0
	for i := 0; i < length; i++ {
		for maxCount < k {
			secondPointer++
			if secondPointer >= length {
				break
			}
			if nums[secondPointer] == max {
				maxCount++
			}
		}
		if maxCount == k {
			if secondPointer < length {
				result += int64(length - secondPointer)
			} else {
				result++
			}
		}
		if nums[i] == max {
			maxCount--
		}
	}
	return result
}
