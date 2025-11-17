package LeetCode1437CheckIfAll1sAreAtLeastLengthKPlacesAway

func kLengthApart(nums []int, k int) bool {
	distance := k
	for _, num := range nums {
		if num == 1 {
			if distance < k {
				return false
			}
			distance = 0
			continue
		}
		distance++
	}
	return true
}
