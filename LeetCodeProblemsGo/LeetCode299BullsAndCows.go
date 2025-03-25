package main

import "fmt"

func getHint(secret string, guess string) string {
	secretMap := make(map[byte]int)
	guessMap := make(map[byte]int)
	bulls := 0
	length := len(secret)
	for i := 0; i < length; i++ {
		if secret[i] == guess[i] {
			bulls++
			continue
		}
		if _, exists := guessMap[guess[i]]; !exists {
			guessMap[guess[i]] = 0
		}
		guessMap[guess[i]]++
		if _, exists := secretMap[secret[i]]; !exists {
			secretMap[secret[i]] = 0
		}
		secretMap[secret[i]]++
	}
	cows := 0
	for key, value := range secretMap {
		if guessValue, exists := guessMap[key]; exists {
			cows += min(value, guessValue)
		}
	}
	return fmt.Sprintf("%vA%vB", bulls, cows)
}
