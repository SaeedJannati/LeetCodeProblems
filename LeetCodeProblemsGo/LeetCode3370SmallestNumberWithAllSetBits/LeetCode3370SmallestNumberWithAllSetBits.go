package LeetCode3370SmallestNumberWithAllSetBits

func smallestNumber(n int) int {
	candidate := 1
	for candidate <= n {
		candidate <<= 1
	}
	return candidate - 1
}
