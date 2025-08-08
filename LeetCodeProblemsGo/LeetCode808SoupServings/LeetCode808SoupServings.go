package LeetCode808SoupServings

func recurse(memoisation [][]float64, aRemain, bRemain int) float64 {
	if aRemain <= 0 && bRemain <= 0 {
		return .5
	}
	if aRemain <= 0 {
		return 1
	}
	if bRemain <= 0 {
		return 0
	}
	if memoisation[aRemain][bRemain] > 0 {
		return memoisation[aRemain][bRemain]
	}
	memoisation[aRemain][bRemain] = 0
	memoisation[aRemain][bRemain] += recurse(memoisation, aRemain-4, bRemain)
	memoisation[aRemain][bRemain] += recurse(memoisation, aRemain-3, bRemain-1)
	memoisation[aRemain][bRemain] += recurse(memoisation, aRemain-2, bRemain-2)
	memoisation[aRemain][bRemain] += recurse(memoisation, aRemain-1, bRemain-3)
	memoisation[aRemain][bRemain] *= .25
	return memoisation[aRemain][bRemain]
}
func soupServings(n int) float64 {
	if n > 4300 {
		return 1
	}
	m := (n + 24) / 25
	memoistaion := make([][]float64, m+1)
	for i := 0; i <= m; i++ {
		memoistaion[i] = make([]float64, m+1)
	}
	return recurse(memoistaion, m, m)
}
