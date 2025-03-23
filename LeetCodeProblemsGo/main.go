package main

import "fmt"

func main() {
	n := 7
	trees := generateTrees(n)
	for _, tree := range trees {
		tree.PrintPreOrderTaraversal()
		tree.PrintInOrderTraversal()
	}
	fmt.Println("")
	rawScriptName := "1976. Number of Ways to Arrive at Destination"
	printScriptName(rawScriptName)
}
