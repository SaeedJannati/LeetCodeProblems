package main

func rob(root *TreeNode) int {
	memoisation := make(map[*TreeNode][]int)
	withRootMax, withoutRootMax := calcMaxMoneyOfNode(root, memoisation)
	return max(withRootMax, withoutRootMax)
}

func calcMaxMoneyOfNode(node *TreeNode, memoisation map[*TreeNode][]int) (int, int) {
	if node == nil {
		return 0, 0
	}
	if value, exists := memoisation[node]; exists {
		return value[0], value[1]
	}
	leftMaxWith, leftMaxWithout := calcMaxMoneyOfNode(node.Left, memoisation)
	rightMaxWith, rightMaxWithout := calcMaxMoneyOfNode(node.Right, memoisation)
	maxWith := node.Val + leftMaxWithout + rightMaxWithout
	maxWithout := max(leftMaxWith, leftMaxWithout) + max(rightMaxWith, rightMaxWithout)
	memoisation[node] = []int{maxWith, maxWithout}
	return maxWith, maxWithout
}
