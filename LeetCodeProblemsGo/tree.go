package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func (node *TreeNode) PrintInOrderTraversal() {
	fmt.Print("InOrder:{")
	node.printInOrderTraversalRecurse()
	fmt.Println("}")
}
func (node *TreeNode) printInOrderTraversalRecurse() {
	if node.Left != nil {
		node.Left.printInOrderTraversalRecurse()
	}
	fmt.Printf("%v,", node.Val)
	if node.Right != nil {
		node.Right.printInOrderTraversalRecurse()
	}
}
func (node *TreeNode) PrintPreOrderTaraversal() {
	fmt.Print("PreOrder:{")
	node.printPreorderTraversalRecursive()
	fmt.Println("},")
}
func (node *TreeNode) printPreorderTraversalRecursive() {
	fmt.Printf("%v,", node.Val)
	if node.Left != nil {
		node.Left.printPreorderTraversalRecursive()
	}
	if node.Right != nil {
		node.Right.printPreorderTraversalRecursive()
	}
}
