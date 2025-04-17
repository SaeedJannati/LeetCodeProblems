package main

import (
	"LeetCodeProblemsGo/LeetCode416PartitionEqualSubsetSum"
	"fmt"
)

func main() {
	nums := []int{1, 5, 11, 3}
	LeetCode416PartitionEqualSubsetSum.Calculate(nums)
	fmt.Println("")
	rawScriptName := "2537. Count the Number of Good Subarrays"
	printScriptName(rawScriptName)
}
