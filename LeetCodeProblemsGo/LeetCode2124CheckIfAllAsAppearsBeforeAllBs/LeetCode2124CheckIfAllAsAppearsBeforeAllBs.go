package LeetCode2124CheckIfAllAsAppearsBeforeAllBs

func checkString(s string) bool {
	bAppeared := false
	for _, c := range s {
		if c == 'a' {
			if bAppeared {
				return false
			}
			continue
		}
		bAppeared = true
	}
	return true
}
