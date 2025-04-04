package LeetCode1123LowestCommonAncestorOfDeepestLeaves

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	answer := &TreeNode{}
	maxDepth := 0
	postOrderDepthFind(root, &maxDepth, 0, &answer)
	return answer
}

func postOrderDepthFind(node *TreeNode, maxDepth *int, depth int, answer **TreeNode) int {
	if depth > *maxDepth {
		*maxDepth = depth
	}
	leftDepth := depth
	rightDepth := depth
	if node.Left != nil {
		leftDepth = postOrderDepthFind(node.Left, maxDepth, depth+1, answer)
	}
	if node.Right != nil {
		rightDepth = postOrderDepthFind(node.Right, maxDepth, depth+1, answer)
	}
	if leftDepth == *maxDepth && rightDepth == *maxDepth {
		*answer = node
	}
	if leftDepth > rightDepth {
		return leftDepth
	}
	return rightDepth
}
