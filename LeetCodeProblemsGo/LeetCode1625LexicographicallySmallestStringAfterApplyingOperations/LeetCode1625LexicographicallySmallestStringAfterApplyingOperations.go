package LeetCode1625LexicographicallySmallestStringAfterApplyingOperations

type node struct {
	Value string
	next  *node
}
type stringQueue struct {
	head *node
	tail *node
}

func (q *stringQueue) enqueue(s string) {
	newNode := &node{Value: s}
	if q.tail != nil {
		q.tail.next = newNode
	}
	q.tail = newNode
	if q.head == nil {
		q.head = newNode
	}
}
func (q *stringQueue) isEmpty() bool {
	return q.head == nil
}
func (q *stringQueue) dequeue() string {
	value := q.head.Value
	q.head = q.head.next
	if q.head == nil {
		q.tail = nil
	}
	return value
}
func findLexSmallestString(s string, a int, b int) string {
	visitd := make(map[string]any)
	toCheck := &stringQueue{}
	toCheck.enqueue(s)
	visitd[s] = struct{}{}
	smallest := s
	length := len(s)
	for !toCheck.isEmpty() {
		current := toCheck.dequeue()
		rotated := current[len(current)-b:] + current[:len(current)-b]
		if _, ok := visitd[rotated]; !ok {
			visitd[rotated] = struct{}{}
			toCheck.enqueue(rotated)
			if rotated < smallest {
				smallest = rotated
			}
		}
		moved := []byte(current)
		for i := 1; i < length; i += 2 {
			moved[i] = byte((int(moved[i]-'0')+a)%10 + '0')
		}
		movedStr := string(moved)
		if _, ok := visitd[movedStr]; !ok {
			visitd[movedStr] = struct{}{}
			toCheck.enqueue(movedStr)
			if movedStr < smallest {
				smallest = movedStr
			}
		}
	}
	return smallest
}
