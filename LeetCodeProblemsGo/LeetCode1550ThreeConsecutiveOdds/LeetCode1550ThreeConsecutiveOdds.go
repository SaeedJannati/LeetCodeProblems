package main

func threeConsecutiveOdds(arr []int) bool {
	consecutiveOdds := 0
	for _, num := range arr {
		if num%2 == 1 {
			consecutiveOdds++
			if consecutiveOdds == 3 {
				return true
			}
			continue
		}
		consecutiveOdds = 0
	}
	return false
}
