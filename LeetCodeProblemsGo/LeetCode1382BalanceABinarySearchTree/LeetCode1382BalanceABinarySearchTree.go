package LeetCode1382BalanceABinarySearchTree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inOrderTraversal(node *TreeNode, inOrderTraversalItmes *[]*TreeNode) {
	if node == nil {
		return
	}
	inOrderTraversal(node.Left, inOrderTraversalItmes)
	*inOrderTraversalItmes = append(*inOrderTraversalItmes, node)
	inOrderTraversal(node.Right, inOrderTraversalItmes)
}
func createHightBalancedBst(nodes []*TreeNode, left, right int) *TreeNode {
	if left > right {
		return nil
	}

	mid := (left + right) >> 1
	nodes[mid].Left = createHightBalancedBst(nodes, left, mid-1)
	nodes[mid].Right = createHightBalancedBst(nodes, mid+1, right)
	return nodes[mid]
}
func balanceBST(root *TreeNode) *TreeNode {
	inOrderTraversalItems := []*TreeNode{}
	inOrderTraversal(root, &inOrderTraversalItems)
	for _, node := range inOrderTraversalItems {
		node.Left = nil
		node.Right = nil
	}
	return createHightBalancedBst(inOrderTraversalItems, 0, len(inOrderTraversalItems)-1)
}
