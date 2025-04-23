package LeetCode1399CountLargestGroup

func countLargestGroup(n int) int {
	digitMap := make(map[int]int)
	digitSum := 0
	maxGroupSize := 0
	for i := 1; i <= n; i++ {
		digitSum = getCount(i)
		if _, exists := digitMap[digitSum]; !exists {
			digitMap[digitSum] = 0
		}
		digitMap[digitSum]++
		if digitMap[digitSum] > maxGroupSize {
			maxGroupSize = digitMap[digitSum]
		}
	}
	result := 0
	for _, count := range digitMap {
		if count != maxGroupSize {
			continue
		}
		result++
	}
	return result

}
func getCount(num int) int {
	sum := 0
	for num > 0 {
		sum += num % 10
		num = num / 10
	}
	return sum
}
