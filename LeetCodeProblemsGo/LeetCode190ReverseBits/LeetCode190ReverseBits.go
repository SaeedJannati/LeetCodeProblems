package LeetCode190ReverseBits

func reverseBits(n int) int {
	m := 0
	for i := 0; i < 16; i++ {
		m |= ((n & (1 << (31 - i))) >> (31 - i)) << i
		m |= ((n & (1 << i)) >> i) << (31 - i)
	}
	return m

}
