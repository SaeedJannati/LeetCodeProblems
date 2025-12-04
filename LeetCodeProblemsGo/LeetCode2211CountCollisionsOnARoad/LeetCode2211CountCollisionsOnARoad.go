package LeetCode2211CountCollisionsOnARoad

type node struct {
	value rune
	next  *node
}
type runeStack struct {
	top *node
}

func (stack *runeStack) push(value rune) {
	newNode := &node{value: value, next: stack.top}
	stack.top = newNode
}
func (stack *runeStack) isEmpty() bool {
	return stack.top == nil
}
func (stack *runeStack) peek() rune {
	return stack.top.value
}
func (stack *runeStack) pop() rune {
	value := stack.top.value
	if stack.top.next != nil {
		stack.top = stack.top.next
	} else {
		stack.top = nil
	}
	return value
}

func countCollisions(directions string) int {
	stack := &runeStack{}
	result := 0
	for _, direction := range directions {
		if direction == 'R' {
			stack.push('R')
			continue
		}
		if stack.isEmpty() {
			stack.push(direction)
			continue
		}
		if direction == stack.peek() {
			stack.push(direction)
			continue
		}
		if direction == 'S' {
			if stack.peek() == 'R' {
				for !stack.isEmpty() && stack.peek() == 'R' {
					stack.pop()
					result++
				}
			}
			stack.push('S')
		}
		if direction == 'L' {
			if stack.peek() == 'R' {
				result += 2
				stack.pop()
				for !stack.isEmpty() && stack.peek() == 'R' {
					stack.pop()
					result++
				}
				stack.push('S')
				continue
			}
			if stack.peek() == 'S' {
				result++
			}
		}
	}
	return result
}
