package LeetCode3713LongestBalancedSubstringI

import "fmt"

func longestBalanced(s string) int {

	maxLength := 1
	length := len(s)
	target := 0
	balanced := false
	for i := 0; i < length; i++ {
		occurances := make([]int, 26)
		for j := i; j < length; j++ {
			occurances[s[j]-'a']++
			target = occurances[s[j]-'a']
			balanced = true
			for _, num := range occurances {
				if num == 0 {
					continue
				}
				if num != target {
					balanced = false
					break
				}
			}
			if balanced {
				maxLength = max(maxLength, j-i+1)
			}
		}
	}
	return maxLength
}
func Calculate() {
	s := "zzabccy"
	fmt.Println(longestBalanced(s))
}
