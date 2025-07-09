package main

func findEvenNumbers(digits []int) []int {
	digitFrequencies := make([]int, 10)
	var result []int
	for _, digit := range digits {
		digitFrequencies[digit]++
	}
	requiredFrequencies := 0

	for i := 1; i < 10; i++ {
		if digitFrequencies[i] == 0 {
			continue
		}
		for j := 0; j < 10; j++ {
			if digitFrequencies[j] == 0 {
				continue
			}
			requiredFrequencies = 1
			if i == j {
				requiredFrequencies++
			}
			if digitFrequencies[j] < requiredFrequencies {
				continue
			}
			for k := 0; k < 10; k += 2 {
				if digitFrequencies[k] == 0 {
					continue
				}
				requiredFrequencies = 1
				if i == k {
					requiredFrequencies++
				}
				if j == k {
					requiredFrequencies++
				}
				if digitFrequencies[k] < requiredFrequencies {
					continue
				}
				result = append(result, 100*i+10*j+k)
			}
		}
	}
	return result
}
