package LeetCode869ReorderedPowerOf2

import "fmt"

func reorderedPowerOf2(n int) bool {
	powOfTwo := 1
	powOfTwoMaps := make([][]int, 32)
	for i := 0; i < 32; i++ {
		powOfTwoMaps[i] = getDigitsMap(powOfTwo)
		powOfTwo <<= 1
	}
	numMap := getDigitsMap(n)
	found := false
	for _, powOfTwoMap := range powOfTwoMaps {
		found = true
		for i := 0; i <= 9; i++ {
			if numMap[i] != powOfTwoMap[i] {
				found = false
				break
			}

		}
		if found {
			return true
		}
	}
	return false
}
func getDigitsMap(n int) []int {
	numsMap := make([]int, 10)
	for n > 0 {
		numsMap[n%10]++
		n /= 10
	}
	return numsMap
}
func Calculate() {
	n := 10
	fmt.Printf("result: %t \n", reorderedPowerOf2(n))
}

//less memory but not thar different

// func reorderedPowerOf2(n int) bool {
// 	powOfTwo := 1
// 	numMap := make([]int, 10)
// 	getDigitsMap(n, numMap)
// 	found := false
// 	powOfTwoMap := make([]int, 10)
// 	for i := 0; i < 32; i++ {
// 		for i := 0; i <= 9; i++ {
// 			powOfTwoMap[i] = 0
// 		}
// 		getDigitsMap(powOfTwo, powOfTwoMap)
// 		found = true
// 		for i := 0; i <= 9; i++ {
// 			if numMap[i] != powOfTwoMap[i] {
// 				found = false
// 				break
// 			}

// 		}
// 		if found {
// 			return true
// 		}
// 		powOfTwo <<= 1
// 	}
// 	return false
// }
// func getDigitsMap(n int, numsMap []int) {
// 	for n > 0 {
// 		numsMap[n%10]++
// 		n /= 10
// 	}
// }
