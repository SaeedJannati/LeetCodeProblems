package LeetCode2787WaysToExpressAnIntegerAsSumOfPowers

import "math"

func numberOfWays(n int, x int) int {
	var modulo int64 = 1e9 + 7
	end := n
	begin := 1
	var mid int
	maxNum := -1
	for begin <= end {
		mid = (begin + end) >> 1
		if int(math.Pow(float64(mid), float64(x))) <= n {
			maxNum = max(maxNum, mid)
			begin = mid + 1
			continue
		}
		end = mid - 1
	}
	if maxNum == -1 {
		return 0
	}
	nums := make([]int, maxNum+1)
	for i := 0; i <= maxNum; i++ {
		nums[i] = int(math.Pow(float64(i), float64(x)))
	}
	last := make([]int64, n+1)
	last[0] = 1
	current := make([]int64, n+1)
	for i := 1; i <= maxNum; i++ {
		for j := 0; j <= n; j++ {
			if j >= nums[i] {
				current[j] = last[j] + last[j-nums[i]]
				current[j] %= modulo
				continue
			}
			current[j] = last[j]
		}
		for j := 0; j <= n; j++ {
			last[j] = current[j]
			current[j] = 0
		}
	}
	return int(last[n])
}
