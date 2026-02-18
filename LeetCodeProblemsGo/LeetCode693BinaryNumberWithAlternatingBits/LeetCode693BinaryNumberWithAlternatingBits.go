package LeetCode693BinaryNumberWithAlternatingBits

func hasAlternatingBits(n int) bool {
	return ((n^(n>>1))+1)&n == 0
}
