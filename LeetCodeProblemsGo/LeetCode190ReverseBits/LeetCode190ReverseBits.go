package LeetCode190ReverseBits

func reverseBits(n int) int {
	first, second := 0, 0
	for i := 0; i < 16; i++ {
		first = 0
		if (n & (1 << i)) > 0 {
			first = 1
		}
		second = 0
		if (n & (1 << (31 - i))) > 0 {
			second = 1
		}
		first = first ^ second
		second = first ^ second
		first = first ^ second
		n = (n & ^(1 << i)) | (first << i)
		n = (n & ^(1 << (31 - i))) | (second << (31 - i))
	}
	return n

}
