package LeetCode1488AvoidFloodInTheCity

import "fmt"

func avoidFlood(rains []int) []int {
	length := len(rains)
	result := make([]int, length)
	for i := 0; i < length; i++ {
		result[i] = 1
	}
	filledLakes := make(map[int]int)
	dryDays := []int{}
	for i := 0; i < length; i++ {
		if rains[i] == 0 {
			dryDays = append(dryDays, i)

		} else {
			result[i] = -1
			if day, exists := filledLakes[rains[i]]; exists {
				if len(dryDays) == 0 {
					return []int{}
				}
				begin := 0
				end := len(dryDays) - 1
				mid := 0
				res := len(dryDays)
				for begin <= end {
					mid = (begin + end) >> 1
					if day < dryDays[mid] {
						res = min(res, mid)
						end = mid - 1
						continue
					}
					begin = mid + 1
				}
				if res == len(dryDays) {
					return []int{}
				}
				result[dryDays[res]] = rains[i]
				copy(dryDays[res:], dryDays[res+1:])
				dryDays = dryDays[:len(dryDays)-1]
			}
			filledLakes[rains[i]] = i
		}
	}
	return result
}

func Calculate() {
	rains := []int{1, 0, 2, 0, 3, 0, 2, 0, 0, 0, 1, 2, 3}
	result := avoidFlood(rains)
	fmt.Printf("%v\n", result)
}
