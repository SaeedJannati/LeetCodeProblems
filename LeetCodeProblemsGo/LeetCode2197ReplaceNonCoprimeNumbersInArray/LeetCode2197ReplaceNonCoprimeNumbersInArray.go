package LeetCode2197ReplaceNonCoprimeNumbersInArray

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}
func replaceNonCoprimes(nums []int) []int {
	numsStack := []int{}
	top, current := 0, 0
	for _, num := range nums {
		current = num
		if len(numsStack) > 0 {
			top = numsStack[len(numsStack)-1]
			for gcd(top, current) > 1 {
				current = lcm(top, current)
				numsStack = numsStack[:len(numsStack)-1]
				if len(numsStack) == 0 {
					break
				}
				top = numsStack[len(numsStack)-1]
			}
		}
		numsStack = append(numsStack, current)
	}
	return numsStack
}
