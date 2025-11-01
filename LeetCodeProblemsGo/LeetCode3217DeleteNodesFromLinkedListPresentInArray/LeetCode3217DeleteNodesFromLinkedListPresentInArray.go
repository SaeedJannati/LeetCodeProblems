package LeetCode3217DeleteNodesFromLinkedListPresentInArray

import "LeetCodeProblemsGo/LinkedList"

type ListNode = LinkedList.ListNode

func modifiedList(nums []int, head *ListNode) *ListNode {
	numMap := make(map[int]any)
	for _, num := range nums {
		numMap[num] = struct{}{}
	}
	newHead := head
	var prev *ListNode = nil
	current := head
	for current != nil {
		if _, exists := numMap[current.Val]; exists {
			if prev == nil {
				newHead = current.Next
				current = newHead
				continue
			}
			prev.Next = current.Next
			current = current.Next
			continue
		}
		prev = current
		current = current.Next
	}
	return newHead
}
