package LeetCode2845CountOfInterestingSubarrays

func countInterestingSubarrays(nums []int, modulo int, k int) int64 {

	prefixModMap := make(map[int]int)
	var result int64
	prefixCount := 0
	prefixModMap[0] = 1
	var need int
	var mod int
	for _, num := range nums {
		if num%modulo == k {
			prefixCount++
		}
		need = (prefixCount + modulo - k) % modulo
		if count, exists := prefixModMap[need]; exists {
			result += int64(count)
		}
		mod = prefixCount % modulo
		if _, exists := prefixModMap[mod]; !exists {
			prefixModMap[mod] = 0
		}
		prefixModMap[mod]++
	}
	return result
}
