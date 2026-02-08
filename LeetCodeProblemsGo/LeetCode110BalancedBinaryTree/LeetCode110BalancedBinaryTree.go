package LeetCode110BalancedBinaryTree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func calcHeight(node *TreeNode, notBalanced *bool) int {
	if *notBalanced {
		return 0
	}
	if node == nil {
		return 0
	}
	node.Val = calcHeight(node.Left, notBalanced)
	right := calcHeight(node.Right, notBalanced)
	if node.Val-right > 1 || node.Val-right < -1 {
		*notBalanced = true
		return 0
	}
	node.Val = max(node.Val, right) + 1
	return node.Val
}
func isBalanced(root *TreeNode) bool {
	notBalanced := false
	calcHeight(root, &notBalanced)
	return !notBalanced
}
