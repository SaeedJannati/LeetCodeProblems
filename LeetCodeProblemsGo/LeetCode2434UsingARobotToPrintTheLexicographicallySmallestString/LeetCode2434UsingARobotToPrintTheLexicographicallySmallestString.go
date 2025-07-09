package LeetCode2434UsingARobotToPrintTheLexicographicallySmallestString

import "strings"

func robotWithString(s string) string {
	length := len(s)
	toPrint := []byte{}
	var outPut strings.Builder
	occurances := make([]int, 26)
	var smallestRemaining byte = 'z' + 1
	for i := 0; i < length; i++ {
		occurances[s[i]-'a']++
		if s[i]-'a' < smallestRemaining {
			smallestRemaining = s[i] - 'a'
		}
	}
	for i := 0; i < length; i++ {
		for toLength := len(toPrint); toLength > 0 && toPrint[toLength-1]-'a' <= smallestRemaining; {
			outPut.WriteByte(toPrint[toLength-1])
			toPrint = toPrint[:toLength-1]
			toLength--
		}
		if s[i]-'a' == smallestRemaining {
			outPut.WriteByte(s[i])
			occurances[smallestRemaining]--
			if occurances[smallestRemaining] == 0 {
				for j := smallestRemaining + 1; j < 26; j++ {
					if occurances[j] > 0 {
						smallestRemaining = j
						break
					}
				}
			}
			continue
		}
		toPrint = append(toPrint, s[i])
		occurances[s[i]-'a']--
	}
	for len(toPrint) > 0 {
		outPut.WriteByte(toPrint[len(toPrint)-1])
		toPrint = toPrint[:len(toPrint)-1]
	}
	return outPut.String()
}
