package LeetCode430FlattenAMultilevelDoublyLinkedList

type Node struct {
	Val   int
	Prev  *Node
	Next  *Node
	Child *Node
}

func flatten(root *Node) *Node {
	node := root
	for node != nil {
		SetNext(node)
		node = node.Next
	}
	return root
}

func SetNext(node *Node) {
	if node.Child == nil {
		return
	}
	var previous *Node = nil
	next := node.Next
	childrenHead := node.Child
	node.Next = childrenHead
	node.Child = nil
	childrenHead.Prev = node
	for childrenHead != nil {
		if childrenHead.Child != nil {
			SetNext(childrenHead)
		}
		previous = childrenHead
		childrenHead = childrenHead.Next
	}
	previous.Next = next
	if next != nil {
		next.Prev = previous
	}
}
