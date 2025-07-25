package LeetCode907SumOfSubarrayMinimums

func sumSubarrayMins(arr []int) int {
	var modulo int64 = 1e9 + 7
	length := len(arr)
	leftFirstSmaller := make([]int, length)
	rightFirstSamaller := make([]int, length)
	monotonique := &Stack{}
	monotonique.initialise()
	monotonique.push([]int{arr[0], 0})
	leftFirstSmaller[0] = -1
	for i := 1; i < length; i++ {
		for (!monotonique.isEmpty()) && monotonique.peek()[0] > arr[i] {
			monotonique.pop()
		}
		if monotonique.isEmpty() {
			leftFirstSmaller[i] = -1
			monotonique.push([]int{arr[i], i})
			continue
		}
		leftFirstSmaller[i] = monotonique.peek()[1]
		monotonique.push([]int{arr[i], i})
	}
	monotonique.initialise()
	rightFirstSamaller[length-1] = length
	monotonique.push([]int{arr[length-1], length - 1})
	for i := length - 2; i >= 0; i-- {
		for (!monotonique.isEmpty()) && monotonique.peek()[0] >= arr[i] {
			monotonique.pop()
		}
		if monotonique.isEmpty() {
			rightFirstSamaller[i] = length
			monotonique.push([]int{arr[i], i})
			continue
		}
		rightFirstSamaller[i] = monotonique.peek()[1]
		monotonique.push([]int{arr[i], i})
	}
	var result int64 = 0
	var delta int64 = 0
	for i := 0; i < length; i++ {
		delta = int64(arr[i])
		delta *= int64(i - leftFirstSmaller[i])
		delta %= modulo
		delta *= int64(rightFirstSamaller[i] - i)
		delta %= modulo
		result += delta
		result %= modulo
	}
	return int(result)
}

type Stack struct {
	items [][]int
}

func (s *Stack) initialise() {
	s.items = [][]int{}
}
func (s *Stack) isEmpty() bool {
	return len(s.items) == 0

}
func (s *Stack) peek() []int {
	return s.items[len(s.items)-1]
}
func (s *Stack) pop() []int {
	top := s.peek()
	s.items = s.items[:len(s.items)-1]
	return top
}
func (s *Stack) push(pair []int) {
	s.items = append(s.items, pair)
}
