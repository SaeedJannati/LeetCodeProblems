package LeetCode1323Maximum69Number

func maximum69Number(num int) int {
	s := &stack{}
	for num > 0 {
		s.push(num % 10)
		num /= 10
	}
	result := 0
	changed := false
	newDigit := 0
	for !s.isEmpty() {
		if changed {
			newDigit = s.pop()
		} else if !changed && s.Top.Value == 6 {
			s.pop()
			newDigit = 9
			changed = true
		} else {
			newDigit = s.pop()
		}
		result += newDigit
		result *= 10
	}
	return result / 10
}

type stack struct {
	Top *node
}

func (s *stack) push(value int) {
	if s.Top == nil {
		s.Top = &node{Value: value}
		return
	}
	newNode := &node{Value: value, Next: s.Top}
	s.Top = newNode
}
func (s *stack) isEmpty() bool {
	return s.Top == nil
}
func (s *stack) pop() int {
	value := s.Top.Value
	newNode := s.Top.Next
	s.Top.Next = nil
	s.Top = newNode
	return value
}

type node struct {
	Value int
	Next  *node
}
