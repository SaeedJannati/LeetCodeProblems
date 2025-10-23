package LeetCode3461CheckIfDigitsAreEqualInStringAfterOperationsI

func hasSameDigits(s string) bool {
	var newString []byte
	for len(s) > 2 {
		newString = []byte{}
		for i, e := 0, len(s)-1; i < e; i++ {
			newString = append(newString, (s[i]-'0'+s[i+1]-'0')%10+'0')
		}
		s = string(newString)
	}
	return s[0] == s[1]
}
