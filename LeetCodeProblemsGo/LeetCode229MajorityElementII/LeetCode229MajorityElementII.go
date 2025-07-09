package LeetCode229MajorityElementII

func majorityElement(nums []int) []int {
	lengthThird := len(nums) / 3
	firstCandiate := 0
	firstVotes := 0
	secondCandidate := 0
	secondVotes := 0
	for _, num := range nums {
		if num == firstCandiate {
			firstVotes++
			continue
		}
		if num == secondCandidate {
			secondVotes++
			continue
		}
		if firstVotes == 0 {
			firstCandiate = num
			firstVotes++
			continue
		}
		if secondVotes == 0 {
			secondCandidate = num
			secondVotes++
			continue
		}
		firstVotes--
		secondVotes--
	}
	result := []int{}
	firstVotes = 0
	secondVotes = 0
	for _, num := range nums {
		if num == firstCandiate {
			firstVotes++
			continue
		}
		if num == secondCandidate {
			secondVotes++
			continue
		}
	}
	if firstVotes > lengthThird {
		result = append(result, firstCandiate)
	}
	if secondVotes > lengthThird {
		result = append(result, secondCandidate)
	}
	return result
}
