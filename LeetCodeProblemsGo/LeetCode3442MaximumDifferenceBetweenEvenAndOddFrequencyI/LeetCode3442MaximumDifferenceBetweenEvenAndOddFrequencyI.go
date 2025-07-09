package LeetCode3442MaximumDifferenceBetweenEvenAndOddFrequencyI

func maxDifference(s string) int {
	frequencies := make([]byte, 26)
	for _, c := range s {
		frequencies[c-'a']++
	}
	maxOdd := 0
	minEven := 101
	frequency := 0
	for _, f := range frequencies {
		frequency = int(f)
		if frequency%2 == 1 {
			if frequency > maxOdd {
				maxOdd = frequency
			}
			continue
		}
		if frequency == 0 {
			continue
		}
		if frequency < minEven {
			minEven = frequency
		}
	}
	return maxOdd - minEven
}
