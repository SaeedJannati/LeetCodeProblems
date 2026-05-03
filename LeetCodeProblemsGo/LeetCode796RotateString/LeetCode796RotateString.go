package LeetCode796RotateString

func rotateString(s string, goal string) bool {
	if len(s) != len(goal) {
		return false
	}
	index := 0
	for i, e := 0, len(s); i < e; i++ {
		if s[0] != goal[i] {
			continue
		}
		isMatch := true
		for j := 1; j < e; j++ {
			index = (i + j) % e
			if s[j] != goal[index] {
				isMatch = false
				break
			}
		}
		if isMatch {
			return true
		}
	}
	return false
}
