package LeetCode3021AliceAndBobPlayingFlowerGame

func flowerGame(n int, m int) int64 {
	var firstEven int64 = int64(n / 2)
	var firstOdd int64 = int64(n - n/2)
	var secondEven int64 = int64(m / 2)
	var secondOdd int64 = int64(m - m/2)
	return firstEven*secondOdd + secondEven*firstOdd
}
