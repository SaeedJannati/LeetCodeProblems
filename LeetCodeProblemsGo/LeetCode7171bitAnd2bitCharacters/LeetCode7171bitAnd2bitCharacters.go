package LeetCode7171bitAnd2bitCharacters

func canBeFormed(bits []int, index int, result *bool) {
	if *result {
		return
	}
	if index == -1 {
		*result = true
		return
	}
	if bits[index] == 0 {
		canBeFormed(bits, index-1, result)
	}
	if index > 0 {
		if bits[index-1] == 0 {
			return
		}
		canBeFormed(bits, index-2, result)

	}

}
func isOneBitCharacter(bits []int) bool {
	length := len(bits)
	if length == 0 {
		return false
	}
	if length == 1 {
		return bits[0] == 0
	}
	if bits[length-1] == 1 {
		return false
	}
	if bits[length-2] == 0 {
		return true
	}
	result := false
	canBeFormed(bits, length-3, &result)
	return !result
}
