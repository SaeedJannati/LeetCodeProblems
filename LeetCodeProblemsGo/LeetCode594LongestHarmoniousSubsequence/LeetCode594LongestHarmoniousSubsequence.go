package LeetCode594LongestHarmoniousSubsequence

func findLHS(nums []int) int {
	numsMap := make(map[int]int)
	for _, num := range nums {
		numsMap[num]++
	}
	current := 0
	max := 0
	for key, value := range numsMap {
		current = value
		if _, exists := numsMap[key+1]; !exists {
			continue
		}
		current += numsMap[key+1]
		if current > max {
			max = current
		}
	}
	return max
}
