package main

import (
	"LeetCodeProblemsGo/LeetCode416PartitionEqualSubsetSum"
	"fmt"
)

func main() {
	nums := []int{1, 5, 11, 3}
	LeetCode416PartitionEqualSubsetSum.Calculate(nums)
	fmt.Println("")
	rawScriptName := "416. Partition Equal Subset Sum"
	printScriptName(rawScriptName)
}
