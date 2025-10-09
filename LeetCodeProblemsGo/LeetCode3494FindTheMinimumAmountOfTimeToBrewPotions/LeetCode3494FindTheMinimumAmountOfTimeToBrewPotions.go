package LeetCode3494FindTheMinimumAmountOfTimeToBrewPotions

func minTime(skills []int, manas []int) int64 {
	skillLength := len(skills)
	endTimes := make([]int64, skillLength)
	roundPrefix := make([]int64, skillLength)
	var roundStartTime int64 = 0
	for _, mana := range manas {
		for i := 1; i < skillLength; i++ {
			roundPrefix[i] = int64(skills[i-1] * mana)
			roundPrefix[i] += roundPrefix[i-1]
		}
		roundStartTime = 0
		for i := 0; i < skillLength; i++ {
			roundStartTime = max(roundStartTime, endTimes[i]-roundPrefix[i])
		}
		for i := 0; i < skillLength; i++ {
			endTimes[i] = roundPrefix[i] + roundStartTime + int64(mana*skills[i])
		}
	}
	return endTimes[skillLength-1]
}
