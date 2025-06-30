package LeetCode429NaryTreeLevelOrderTraversal

type Node struct {
	Val      int
	Children []*Node
}

func levelOrder(root *Node) [][]int {
	result := [][]int{}
	if root == nil {
		return result
	}
	currentLayer := []*Node{}
	nextLayer := []*Node{}
	currentLayer = append(currentLayer, root)
	for len(currentLayer) > 0 {
		layer := []int{}
		for len(currentLayer) > 0 {
			node := currentLayer[0]
			layer = append(layer, node.Val)
			currentLayer = currentLayer[1:]
			for _, child := range node.Children {
				nextLayer = append(nextLayer, child)
			}
		}
		result = append(result, layer)
		for len(nextLayer) > 0 {
			currentLayer = append(currentLayer, nextLayer[0])
			nextLayer = nextLayer[1:]
		}
	}
	return result
}
