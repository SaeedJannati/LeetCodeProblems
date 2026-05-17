package LeetCode1306JumpGameIII

func canReach(arr []int, start int) bool {
	if arr[start] == 0 {
		return true
	}
	length := len(arr)
	visited := make([]bool, length)
	queue := &IntQueue{}
	queue.Enqueue(start)
	visited[start] = true
	next := 0
	for !queue.IsEmpty() {
		current := queue.Dequeue()
		for i := -1; i < 2; i += 2 {
			next = current + i*arr[current]
			if next < 0 || next >= length || visited[next] {
				continue
			}
			if arr[next] == 0 {
				return true
			}
			queue.Enqueue(next)
			visited[next] = true
		}
	}
	return false
}

type IntQueue struct {
	head *Node
	tail *Node
}
type Node struct {
	value int
	next  *Node
}

func (q *IntQueue) Enqueue(value int) {
	if q.head == nil {
		q.head = &Node{value: value}
		q.tail = q.head
	} else {
		q.tail.next = &Node{value: value}
		q.tail = q.tail.next
	}
}
func (q *IntQueue) Dequeue() int {
	if q.head == nil {
		return -1
	}
	value := q.head.value
	q.head = q.head.next
	if q.head == nil {
		q.tail = nil
	}
	return value
}
func (q *IntQueue) IsEmpty() bool {
	return q.head == nil
}
