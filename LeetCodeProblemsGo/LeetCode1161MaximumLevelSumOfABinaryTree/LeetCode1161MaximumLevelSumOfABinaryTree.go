package LeetCode1161MaximumLevelSumOfABinaryTree

import "math"

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxLevelSum(root *TreeNode) int {
	maxSum := math.MinInt32
	maxIndex := 1
	currentSum := 0
	currentIndex := 0
	currentLevel := queue{}
	nextLevel := queue{}
	currentLevel.push(root)
	for !currentLevel.isEmpty() {
		currentSum = 0
		currentIndex++
		for !currentLevel.isEmpty() {
			node := currentLevel.pop()
			currentSum += node.Val
			if node.Left != nil {
				nextLevel.push(node.Left)
			}
			if node.Right != nil {
				nextLevel.push(node.Right)
			}
		}
		if currentSum > maxSum {
			maxSum = currentSum
			maxIndex = currentIndex
		}
		for !nextLevel.isEmpty() {
			currentLevel.push(nextLevel.pop())
		}
	}
	return maxIndex
}

type linkedListNode struct {
	value *TreeNode
	next  *linkedListNode
}
type queue struct {
	head *linkedListNode
	tail *linkedListNode
}

func (queue *queue) isEmpty() bool {
	return queue.head == nil
}
func (queue *queue) pop() *TreeNode {
	node := queue.head.value
	if queue.tail == queue.head {
		queue.tail = nil
		queue.head = nil
		return node
	}
	queue.head = queue.head.next
	return node
}
func (queue *queue) push(node *TreeNode) {
	newTail := linkedListNode{
		value: node,
	}
	if queue.head == nil {
		queue.head = &newTail
		queue.tail = &newTail
		return
	}
	queue.tail.next = &newTail
	queue.tail = &newTail

}
