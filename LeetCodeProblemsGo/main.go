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
	rawScriptName := "3394. Check if Grid can be Cut into Sections"
	printScriptName(rawScriptName)
}
