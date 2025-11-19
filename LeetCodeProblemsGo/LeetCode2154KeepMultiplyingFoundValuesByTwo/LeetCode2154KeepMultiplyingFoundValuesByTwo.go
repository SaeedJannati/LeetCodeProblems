package LeetCode2154KeepMultiplyingFoundValuesByTwo

func findFinalValue(nums []int, original int) int {
	numsMap := make(map[int]any)
	for _, num := range nums {
		numsMap[num] = struct{}{}
	}
	for true {
		if _, exists := numsMap[original]; !exists {
			return original
		}
		original <<= 1
	}
	return original
}
