package LeetCode2410MaximumMatchingOfPlayersWithTrainers

import "sort"

func matchPlayersAndTrainers(players []int, trainers []int) int {
	sort.Slice(players, func(i, j int) bool {
		return players[i] < players[j]
	})
	sort.Slice(trainers, func(i, j int) bool {
		return trainers[i] < trainers[j]
	})
	playersLength := len(players)
	playerPointer := 0
	trainersLength := len(trainers)
	trainerPointer := 0
	result := 0
	for playerPointer < playersLength && trainerPointer < trainersLength {
		if players[playerPointer] > trainers[trainerPointer] {
			trainerPointer++
			continue
		}
		playerPointer++
		trainerPointer++
		result++
	}
	return result
}
