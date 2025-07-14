package LeetCode1290ConvertBinaryNumberInALinkedListToInteger

type ListNode struct {
	Val  int
	Next *ListNode
}

func getDecimalValue(head *ListNode) int {
	result := 0
	node := head
	for node != nil {
		result = (result << 1) | node.Val
		node = node.Next
	}
	return result
}
