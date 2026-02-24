package LeetCode1022SumOfRootToLeafBinaryNumbers

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(node *TreeNode, current int, sum *int) {
	if node == nil {
		return
	}
	current = current<<1 | node.Val
	if node.Left == nil && node.Right == nil {
		*sum += current
		return
	}
	dfs(node.Left, current, sum)
	dfs(node.Right, current, sum)
}
func sumRootToLeaf(root *TreeNode) int {
	sum := 0
	dfs(root, 0, &sum)
	return sum
}
