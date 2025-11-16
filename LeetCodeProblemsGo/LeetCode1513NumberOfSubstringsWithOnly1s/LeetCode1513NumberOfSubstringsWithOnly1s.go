package LeetCode1513NumberOfSubstringsWithOnly1s

func numSub(s string) int {
	var result int64 = 0
	var delta int64
	var mod int64 = 1e9 + 7
	consecutinveOnesCount := 0
	for _, c := range s {
		if c == '1' {
			consecutinveOnesCount++
			continue
		}
		if consecutinveOnesCount > 0 {
			delta = int64(consecutinveOnesCount)
			delta *= delta + 1
			delta /= 2
			delta %= mod
			result += delta
			result %= mod
			consecutinveOnesCount = 0
		}
	}
	if consecutinveOnesCount > 0 {
		delta = int64(consecutinveOnesCount)
		delta *= delta + 1
		delta /= 2
		delta %= mod
		result += delta
		result %= mod
		consecutinveOnesCount = 0
	}
	return int(result)
}
