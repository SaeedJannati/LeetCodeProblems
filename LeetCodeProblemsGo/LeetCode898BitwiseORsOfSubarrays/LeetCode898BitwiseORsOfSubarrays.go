package LeetCode898BitwiseORsOfSubarrays

func subarrayBitwiseORs(arr []int) int {
	result := make(map[int]any)
	current := make(map[int]any)
	for _, num := range arr {
		next := make(map[int]any)
		next[num] = struct{}{}
		for orValue, _ := range current {
			next[orValue|num] = struct{}{}
		}
		current = next
		for orValue, _ := range current {
			result[orValue] = struct{}{}
		}
	}
	return len(result)

}
