package LeetCode187RepeatedDNASequences

import "fmt"

func findRepeatedDnaSequences(s string) []string {
	length := len(s)
	result := make([]string, 0)
	if length < 11 {
		return result
	}
	added := make(map[int]struct{})
	seen := make(map[int]struct{})
	current := 0
	clearMask := (1 << 20) - 1
	for i := 0; i < 10; i++ {
		current <<= 2
		switch s[i] {
		case 'A':
			current |= 0
		case 'C':
			current |= 1
		case 'G':
			current |= 2
		case 'T':
			current |= 3
		}
	}
	seen[current] = struct{}{}
	for i := 10; i < length; i++ {
		current <<= 2
		switch s[i] {
		case 'A':
			current |= 0
		case 'C':
			current |= 1
		case 'G':
			current |= 2
		case 'T':
			current |= 3
		}
		current &= clearMask
		if _, ok := seen[current]; ok {
			if _, exists := added[current]; !exists {
				added[current] = struct{}{}
				result = append(result, s[i-9:i+1])
			}
		} else {
			seen[current] = struct{}{}
		}
	}
	return result
}

func Calculate() {
	s := "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
	result := findRepeatedDnaSequences(s)
	fmt.Printf("%v\n", result)
}
