package LeetCode67924Game

import "math"

func judgePoint24(cards []int) bool {
	signs := make([]byte, 64)
	for i := 0; i < 64; i++ {
		signs[i] = byte(i)
	}
	nums := make([]float64, 4)
	result := false
	visited := make([]bool, 4)
	checkNum(cards, visited, signs, nums, 0, &result)
	return result
}

func applySign(a, b float64, sign byte) float64 {
	switch sign {
	case 0:
		return a + b
	case 1:
		return a - b
	case 2:
		return a * b
	case 3:
		return a / b
	}
	return 0
}

func checkNum(cards []int, visited []bool, signs []byte, nums []float64, index int, result *bool) bool {
	if *result {
		return true
	}
	var res float64 = 0
	if index == 4 {
		for _, sign := range signs {
			res = applySign(applySign(nums[0], applySign(nums[1], nums[2], (sign>>2)&3), sign&3), nums[3],
				(sign>>4)&3)

			res = applySign(applySign(applySign(nums[0], nums[1], sign&3), nums[2], (sign>>2)&3), nums[3],
				(sign>>4)&3)
			if math.Abs(res-24) < .01 {
				return true
			}

			res = applySign(
				nums[0], applySign(applySign(nums[1], nums[2], (sign>>2)&3), nums[3], (sign>>4)&3), sign&3)
			if math.Abs(res-24) < .01 {
				return true
			}
			res = applySign(
				nums[0], applySign(nums[1], applySign(nums[2], nums[3], (sign>>4)&3), (sign>>2)&3), sign&3)
			if math.Abs(res-24) < .01 {
				return true
			}
			res = applySign(applySign(nums[0], nums[1], sign&3), applySign(nums[2], nums[3], (sign>>4)&3),
				(sign>>2)&3)
			if math.Abs(res-24) < .01 {
				return true
			}
		}
		return false
	}

	for i := 0; i < 4; i++ {
		if visited[i] {
			continue
		}
		visited[i] = true
		nums[index] = float64(cards[i])
		if checkNum(cards, visited, signs, nums, index+1, result) {
			*result = true
			return true
		}
		visited[i] = false
	}
	return false
}
