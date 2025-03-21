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
	rawScriptName := "2115. Find All Possible Recipes from Given Supplies"
	printScriptName(rawScriptName)
}
