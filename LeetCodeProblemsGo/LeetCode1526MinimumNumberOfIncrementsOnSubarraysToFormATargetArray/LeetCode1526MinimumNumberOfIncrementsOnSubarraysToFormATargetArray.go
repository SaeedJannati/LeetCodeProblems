package LeetCode1526MinimumNumberOfIncrementsOnSubarraysToFormATargetArray

func minNumberOperations(target []int) int {
	length := len(target)
	moves := target[0]
	for i := 1; i < length; i++ {
		moves += max(0, target[i]-target[i-1])
	}
	return moves
}
