package LeetCode3479FruitsIntoBasketsIII

func buildTree(segmentTree []int, baskets []int, index, start, end int) {
	if start == end {
		segmentTree[index] = baskets[start]
		return
	}
	mid := (start + end) >> 1
	buildTree(segmentTree, baskets, (index<<1)+1, start, mid)
	buildTree(segmentTree, baskets, (index<<1)+2, mid+1, end)
	segmentTree[index] = max(segmentTree[(index<<1)+1], segmentTree[(index<<1)+2])
}
func updateNode(segmetTree []int, index int) {
	if index == 0 {
		return
	}
	parent := (index - 1) >> 1
	segmetTree[parent] = max(segmetTree[(parent<<1)+1], segmetTree[(parent<<1)+2])
	updateNode(segmetTree, parent)
}
func fillBasket(segmentTree []int, index int) {
	segmentTree[index] = 0
	updateNode(segmentTree, index)
}
func query(segmentTree []int, fruit, index, start, end int) {
	if start == end {
		fillBasket(segmentTree, index)
	}
	if fruit > segmentTree[index] {
		return
	}
	mid := (start + end) >> 1

	if fruit <= segmentTree[(index<<1)+1] {
		query(segmentTree, fruit, (index<<1)+1, start, mid)
		return
	}
	if fruit <= segmentTree[(index<<1)+2] {
		query(segmentTree, fruit, (index<<1)+2, mid+1, end)
		return
	}

}
func numOfUnplacedFruits(fruits []int, baskets []int) int {
	length := len(baskets)
	segmentTree := make([]int, length<<2)
	buildTree(segmentTree, baskets, 0, 0, length-1)
	notPlacedFruits := 0
	for _, fruit := range fruits {
		if fruit > segmentTree[0] {
			notPlacedFruits++
			continue
		}
		query(segmentTree, fruit, 0, 0, length-1)
	}
	return notPlacedFruits
}
