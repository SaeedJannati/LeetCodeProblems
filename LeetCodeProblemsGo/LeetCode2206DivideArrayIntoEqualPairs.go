package main

func divideArray(nums []int) bool {
	var numsMap = make(map[int]int)
	for _, num := range nums {
		if _, exists := numsMap[num]; exists {
			numsMap[num]++
			continue
		}
		numsMap[num] = 1
	}
	for _, value := range numsMap {
		if value%2 == 1 {
			return false
		}
	}
	return true
}
