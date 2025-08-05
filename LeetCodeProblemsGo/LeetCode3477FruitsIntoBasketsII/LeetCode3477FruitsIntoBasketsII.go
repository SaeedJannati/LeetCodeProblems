package LeetCode3477FruitsIntoBasketsII

func numOfUnplacedFruits(fruits []int, baskets []int) int {

	fruitsPlaced := 0
	basketsLength := len(baskets)
	for _, fruit := range fruits {
		for i := 0; i < basketsLength; i++ {
			if fruit > baskets[i] {
				continue
			}
			baskets[i] = -1
			fruitsPlaced++
			break
		}
	}
	return len(fruits) - fruitsPlaced
}
