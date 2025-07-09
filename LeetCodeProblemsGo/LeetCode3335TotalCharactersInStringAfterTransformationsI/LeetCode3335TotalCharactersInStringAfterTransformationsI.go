package main

func lengthAfterTransformations(s string, t int) int {
	frequencies := make([]int64, 26)
	for _, char := range s {
		frequencies[char-'a']++
	}
	modulo := int64(1e9 + 7)
	var temp int64
	var temp2 int64
	for i := 0; i < t; i++ {
		temp = 0
		temp2 = 0
		for j := 0; j < 25; j++ {
			temp = frequencies[j] % modulo
			frequencies[j] = temp2
			temp2 = temp
		}

		frequencies[0] += frequencies[25] % modulo
		frequencies[0] %= modulo
		frequencies[1] += frequencies[25] % modulo
		frequencies[1] %= modulo
		frequencies[25] = temp
	}
	var result int64 = 0
	for i := 0; i < 26; i++ {
		result += frequencies[i] % modulo
		result %= modulo
	}
	return int(result)
}
