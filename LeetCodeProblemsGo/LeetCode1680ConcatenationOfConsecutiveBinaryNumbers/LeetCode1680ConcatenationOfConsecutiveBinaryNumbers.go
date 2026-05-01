package leetcode1680concatenationofconsecutivebinarynumbers

func concatenatedBinary(n int) int {
	var mod int64 = 1e9 + 7
	var result int64 = 0
	var bitLength int64 = 0
	for i := 1; i <= n; i++ {
		if (i & (i - 1)) == 0 {
			bitLength++
		}
		result = (result << bitLength) | int64(i)
		result %= mod
	}
	return int(result)
}
