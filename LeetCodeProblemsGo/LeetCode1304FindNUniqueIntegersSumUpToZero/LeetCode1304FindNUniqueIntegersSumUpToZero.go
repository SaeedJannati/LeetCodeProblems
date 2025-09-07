package LeetCode1304FindNUniqueIntegersSumUpToZero

func sumZero(n int) []int {
	result := make([]int, 0, n)
	if n%2 == 1 {
		result = append(result, 0)
	}
	for i, e := 1, n/2; i <= e; i++ {
		result = append(result, i, -i)
	}
	return result
}
