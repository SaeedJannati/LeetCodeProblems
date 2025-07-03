package leetcode3304findthekthcharacterinstringgamei

func kthCharacter(k int) byte {
	if k == 1 {
		return 'a'
	}
	var result byte
	getString("a", 1, k, &result)
	return result
}

func getString(current string, indexBefore, k int, result *byte) {
	length := len(current)
	if length+indexBefore >= k {
		k -= indexBefore
		target := current[k-1]
		target++
		if target > 'z' {
			target = 'a'
		}
		*result = target
		return
	}
	for i := 0; i < length; i++ {
		target := current[i]
		target++
		if target > 'z' {
			target = 'a'
		}
		current += string(rune(target))
	}
	indexBefore += length
	getString(current, indexBefore, k, result)
}
