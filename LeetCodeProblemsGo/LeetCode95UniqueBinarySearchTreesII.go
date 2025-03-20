package main

func generateTrees(n int) []*TreeNode {
	return createSubtrees(1, n)
}

func createSubtrees(begin int, end int) []*TreeNode {
	result := []*TreeNode{}
	if begin > end {
		result = append(result, nil)
		return result
	}
	for i := begin; i <= end; i++ {
		leftNodes := createSubtrees(begin, i-1)
		rightNodes := createSubtrees(i+1, end)
		for _, left := range leftNodes {
			for _, right := range rightNodes {
				node := &TreeNode{Val: i, Left: left, Right: right}
				result = append(result, node)
			}
		}
	}
	return result
}
