package LeetCode756PyramidTransitionMatrix

func canBuild(lastRow, currentRow []byte, allowedMap map[byte][]byte, index int, result *bool) {
	if *result {
		return
	}
	if index == len(lastRow) {
		if len(currentRow) == 1 {
			*result = true
			return
		}
		canBuild(currentRow, []byte{}, allowedMap, 1, result)
		return
	}
	if value, exists := allowedMap[lastRow[index-1]|lastRow[index]<<3]; exists {
		for _, itm := range value {
			canBuild(lastRow, append(currentRow, itm), allowedMap, index+1, result)
		}
	}

}

func pyramidTransition(bottom string, allowed []string) bool {
	allowedMap := make(map[byte][]byte)
	for _, triplet := range allowed {
		key := byte((triplet[0] - 'A') | ((triplet[1] - 'A') << 3))
		if _, exists := allowedMap[key]; !exists {
			allowedMap[key] = []byte{}
		}
		allowedMap[key] = append(allowedMap[key], byte(triplet[2]-'A'))
	}
	lastRow := []byte{}
	for i := 0; i < len(bottom); i++ {
		lastRow = append(lastRow, byte(bottom[i]-'A'))
	}
	result := false
	canBuild(lastRow, []byte{}, allowedMap, 1, &result)
	return result
}
