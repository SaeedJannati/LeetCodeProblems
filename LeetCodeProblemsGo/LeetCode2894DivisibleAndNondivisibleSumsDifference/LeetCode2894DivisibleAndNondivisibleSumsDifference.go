package main

func differenceOfSums(n int, m int) int {
	var sum int64 = int64(1 + n)
	sum *= int64(n)
	sum /= 2
	var sumDivisible int64 = int64(m + (n/m)*m)
	sumDivisible *= int64(n / m)
	sumDivisible /= 2
	return int(sum - 2*sumDivisible)
}
