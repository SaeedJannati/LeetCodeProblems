package LeetCode1717MaximumScoreFromRemovingSubstrings

func maximumGain(s string, x int, y int) int {
	numsStack := &myStack{}
	score := 0
	firstScore := max(x, y)
	firstTarget := "ab"
	secondTarget := "ba"
	if y > x {
		secondTarget = "ab"
		firstTarget = "ba"
	}
	secondScore := min(x, y)
	for _, c := range s {
		if numsStack.isEmpty() {
			numsStack.push(c)
			continue
		}
		if numsStack.peek() == rune(firstTarget[0]) && c == rune(firstTarget[1]) {
			score += firstScore
			numsStack.pop()
			continue
		}
		numsStack.push(c)
	}
	secondStack := &myStack{}
	for !numsStack.isEmpty() {
		c := numsStack.pop()
		if secondStack.isEmpty() {
			secondStack.push(c)
			continue
		}
		if secondStack.peek() == rune(secondTarget[1]) && c == rune(secondTarget[0]) {
			score += secondScore
			secondStack.pop()
			continue
		}
		secondStack.push(c)
	}
	return score
}

type myStack struct {
	elements []rune
}

func (s *myStack) push(c rune) {
	s.elements = append(s.elements, c)
}
func (s *myStack) isEmpty() bool {
	return len(s.elements) == 0
}
func (s *myStack) peek() rune {
	return s.elements[len(s.elements)-1]
}
func (s *myStack) pop() rune {
	top := s.peek()
	s.elements = s.elements[:len(s.elements)-1]
	return top
}
