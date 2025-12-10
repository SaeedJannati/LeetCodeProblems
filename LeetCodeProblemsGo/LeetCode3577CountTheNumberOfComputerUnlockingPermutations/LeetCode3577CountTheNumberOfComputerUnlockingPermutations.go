package LeetCode3577CountTheNumberOfComputerUnlockingPermutations

func countPermutations(complexity []int) int {
	firstItem := complexity[0]

	length := len(complexity)
	for i := 1; i < length; i++ {
		if complexity[i] <= firstItem {
			return 0
		}
	}
	var mod int64 = 1e9 + 7
	var result int64 = 1
	for i := 1; i < length; i++ {
		result *= int64(i)
		result %= mod
	}
	return int(result)
}
