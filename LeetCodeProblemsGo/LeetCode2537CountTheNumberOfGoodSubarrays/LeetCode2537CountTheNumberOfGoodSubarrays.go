package LeetCode2537CountTheNumberOfGoodSubarrays

func countGood(nums []int, k int) int64 {
	length := len(nums)
	if length == 1 {
		return 0
	}
	var result int64 = 0
	var totalCount int64 = int64(length) * int64(length+1) / 2
	memo := make(map[int]int64)
	numCount := make(map[int]int)
	var pairCount int64 = 0
	firstPointer := 0
	secondPointer := 0
	numCount[nums[0]] = 1
	for firstPointer < length {
		for pairCount < int64(k) && secondPointer < length {
			secondPointer++
			if secondPointer == length {
				break
			}
			if _, exists := numCount[nums[secondPointer]]; !exists {
				numCount[nums[secondPointer]] = 0
			}
			pairCount -= getPermutationsCount(numCount[nums[secondPointer]], memo)
			numCount[nums[secondPointer]]++
			pairCount += getPermutationsCount(numCount[nums[secondPointer]], memo)
		}
		if secondPointer > length-1 {
			secondPointer = length - 1
		}
		var delta int64 = 0
		if pairCount < int64(k) {
			delta = 1
		}
		result += int64(secondPointer) - int64(firstPointer) + delta
		pairCount -= getPermutationsCount(numCount[nums[firstPointer]], memo)
		numCount[nums[firstPointer]]--
		pairCount += getPermutationsCount(numCount[nums[firstPointer]], memo)
		firstPointer++
		for pairCount >= int64(k) && firstPointer <= secondPointer {
			pairCount -= getPermutationsCount(numCount[nums[secondPointer]], memo)
			numCount[nums[secondPointer]]--
			pairCount += getPermutationsCount(numCount[nums[secondPointer]], memo)
			secondPointer--
		}
	}
	return totalCount - result
}

func getPermutationsCount(count int, memo map[int]int64) int64 {
	if count == 0 || count == 1 {
		return 0
	}
	if num, exists := memo[count]; exists {
		return num
	}
	memo[count] = int64(count) * int64(count-1) / 2
	return memo[count]
}
