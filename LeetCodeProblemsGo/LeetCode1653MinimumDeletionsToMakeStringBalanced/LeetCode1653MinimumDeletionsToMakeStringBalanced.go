package LeetCode1653MinimumDeletionsToMakeStringBalanced

import "fmt"

func minimumDeletions(s string) int {
	length := len(s)
	aAfter := make([]int, length)
	bBefore := make([]int, length)
	for i := 1; i < length; i++ {
		bBefore[i] = bBefore[i-1]
		if s[i-1] != 'b' {
			continue
		}
		bBefore[i]++
	}
	for i := length - 2; i >= 0; i-- {
		aAfter[i] = aAfter[i+1]
		if s[i+1] != 'a' {
			continue
		}
		aAfter[i]++
	}
	minRemove := length
	toRemove := 0

	for i := 0; i < length; i++ {
		toRemove = aAfter[i] + bBefore[i]
		minRemove = min(minRemove, toRemove)
	}

	return minRemove
}

func Calculate() {
	s := "ababaaaabbbbbaaababbbbbbaaabbaababbabbbbaabbbbaabbabbabaabbbababaa"
	fmt.Println(minimumDeletions(s))
}
