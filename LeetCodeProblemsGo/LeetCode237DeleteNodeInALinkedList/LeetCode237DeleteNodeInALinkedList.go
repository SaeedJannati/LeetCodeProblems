package leetcode237deletenodeinalinkedlist

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteNode(node *ListNode) {
	var current *ListNode = node
	var next *ListNode
	for current.Next != nil {
		next = current.Next
		current.Val = next.Val
		if next.Next == nil {
			current.Next = nil
			return
		}
		current = next
	}
}
