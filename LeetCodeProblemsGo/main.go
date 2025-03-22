package main

import "fmt"

func main() {
	n := 1
	trees := generateTrees(n)
	for _, tree := range trees {
		tree.PrintPreOrderTaraversal()
		tree.PrintInOrderTraversal()
	}
	fmt.Println("")
	rawScriptName := "2685. Count the Number of Complete Components"
	printScriptName(rawScriptName)
}
