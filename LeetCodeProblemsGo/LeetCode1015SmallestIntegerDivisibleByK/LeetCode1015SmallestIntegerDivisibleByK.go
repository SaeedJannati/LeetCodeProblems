package LeetCode1015SmallestIntegerDivisibleByK

func smallestRepunitDivByK(k int) int {
	if k%2 == 0 || k%5 == 0 {
		return -1
	}
	if k <= 1 {
		return 1
	}
	mod := 1
	length := 1
	modOfLargerPart := make(map[int]any)
	for {
		length++
		mod *= 10
		mod %= k
		if _, exists := modOfLargerPart[mod]; exists {
			return -1
		}
		modOfLargerPart[mod] = nil
		mod = (mod + 1) % k
		if mod == 0 {
			return length
		}
	}
}
