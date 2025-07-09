package LeetCode2900LongestUnequalAdjacentGroupsSubsequenceI

func getLongestSubsequence(words []string, groups []int) []string {
	previousValue := groups[0]
	length := len(words)
	result := []string{words[0]}
	for i := 1; i < length; i++ {
		if groups[i] == previousValue {
			continue
		}
		previousValue = groups[i]
		result = append(result, words[i])
	}
	return result
}
