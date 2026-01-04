package LeetCode1390FourDivisors

import "math"

//	func sumFourDivisors(nums []int) int {
//		totalSum := 0
//		divisorSum := 0
//		divisorCount := 0
//		for _, num := range nums {
//			divisorSum = 1
//			divisorCount = 1
//			for i := 2; i <= num/2; i++ {
//				if num%i == 0 {
//					divisorSum += i
//					divisorCount++
//					if divisorCount > 3 {
//						break
//					}
//				}
//			}
//			if divisorCount == 3 {
//				totalSum += divisorSum + num
//			}
//		}
//		return totalSum
//	}
func sumFourDivisors(nums []int) int {
	totalSum := 0
	divisorSum := 0
	divisorCount := 0
	divisorCap := 0
	otherDivisor := 0
	for _, num := range nums {
		divisorSum = 1
		divisorCount = 1
		divisorCap = int(math.Sqrt(float64(num)))
		for i := 2; i <= divisorCap; i++ {
			if num%i == 0 {
				divisorSum += i
				divisorCount++
				otherDivisor = num / i
				if otherDivisor != i {
					divisorSum += otherDivisor
					divisorCount++
				}
				if divisorCount > 3 {
					break
				}
			}
		}
		if divisorCount == 3 {
			totalSum += divisorSum + num
		}
	}
	return totalSum
}

func Calculate() {
	nums := []int{21, 4, 7}
	sum := sumFourDivisors(nums)
	println(sum)
}
