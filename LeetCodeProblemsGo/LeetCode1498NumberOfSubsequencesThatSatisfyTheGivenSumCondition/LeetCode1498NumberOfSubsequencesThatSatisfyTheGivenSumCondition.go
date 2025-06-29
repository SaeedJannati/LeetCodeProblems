package LeetCode1498NumberOfSubsequencesThatSatisfyTheGivenSumCondition

import "sort"

func moduloPow(base, power, mod int) int {

	var result int64 = 1
	if power == 0 {
		return int(result)
	}
	if power == 1 {
		return base
	}
	var pow2 int64 = int64(base)
	currentPower := 1
	for currentPower <= power {
		if (power & currentPower) == currentPower {
			result *= (pow2 % int64(mod))
			result %= int64(mod)
		}
		currentPower *= 2
		pow2 *= (pow2)
		pow2 %= int64(mod)
	}
	return int(result)
}
func numSubseq(nums []int, target int) int {
	var mod int = 1e9 + 7
	var sum int64 = 0
	length := len(nums)
	begin := 0
	end := length - 1
	mid := 0
	foundIndex := 0
	delta := 0
	sort.Ints(nums)
	for i := 0; i < length; i++ {
		begin = i
		end = length - 1
		foundIndex = -1
		for begin <= end {
			mid = (begin + end) / 2
			if nums[i]+nums[mid] <= target {
				if mid > foundIndex {
					foundIndex = mid
				}
				begin = mid + 1
				continue
			}
			end = mid - 1
		}
		if foundIndex == -1 {
			continue
		}
		delta = foundIndex - i + 1
		sum += int64(moduloPow(2, delta-1, mod))
		sum %= int64(mod)
	}
	return int(sum)
}
