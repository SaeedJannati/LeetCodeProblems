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
	rawScriptName := "2140. Solving Questions With Brainpower"
	printScriptName(rawScriptName)
}
