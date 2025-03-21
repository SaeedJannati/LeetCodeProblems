package main

import (
	"container/list"
)

func findAllRecipes(recipes []string, ingredients [][]string, supplies []string) []string {
	adjPlus := make(map[string]map[string]bool)
	adjMinus := make(map[string]map[string]bool)
	recipesSet := make(map[string]bool)
	recipesLength := len(recipes)
	for i := 0; i < recipesLength; i++ {
		recipesSet[recipes[i]] = true
		adjMinus[recipes[i]] = make(map[string]bool)
		for _, item := range ingredients[i] {
			if _, exists := adjPlus[item]; !exists {
				adjPlus[item] = make(map[string]bool)
			}
			adjPlus[item][recipes[i]] = true
			adjMinus[recipes[i]][item] = true

		}
	}
	queue := list.New()
	result := []string{}
	for _, item := range supplies {
		queue.PushBack(item)
	}
	for queue.Len() > 0 {
		node := queue.Remove(queue.Front()).(string)
		if _, exists := adjPlus[node]; !exists {
			continue
		}
		for key, _ := range adjPlus[node] {
			delete(adjMinus[key], node)
			if len(adjMinus[key]) == 0 {
				result = append(result, key)
				queue.PushBack(key)
			}
		}
	}
	return result
}
