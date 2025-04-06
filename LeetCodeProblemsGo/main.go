package main

import (
	"LeetCodeProblemsGo/LeetCode368LargestDivisibleSubset"
	"fmt"
)

func main() {
	nums := []int{1, 2, 4, 8, 16}
	LeetCode368LargestDivisibleSubset.Calculate(nums)
	fmt.Println("")
	rawScriptName := "368. Largest Divisible Subset"
	printScriptName(rawScriptName)
}
