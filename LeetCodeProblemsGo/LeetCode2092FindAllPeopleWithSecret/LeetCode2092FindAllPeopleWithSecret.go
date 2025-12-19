package LeetCode2092FindAllPeopleWithSecret

import "sort"

func find(parents map[int]int, node int) int {
	if parents[node] != node {
		parents[node] = find(parents, parents[node])
	}
	return parents[node]
}
func union(parents map[int]int, ranks map[int]int, first, second int) {
	firstParent := find(parents, first)
	secondParent := find(parents, second)
	if firstParent == secondParent {
		return
	}
	if ranks[firstParent] > ranks[secondParent] {
		parents[secondParent] = firstParent
	} else if ranks[secondParent] > ranks[firstParent] {
		parents[firstParent] = secondParent
	} else {
		parents[secondParent] = firstParent
		ranks[firstParent]++
	}
}
func findAllPeople(n int, meetings [][]int, firstPerson int) []int {
	sort.Slice(meetings, func(i, j int) bool {
		return meetings[i][2] < meetings[j][2]
	})
	result := []int{}
	withSecret := make(map[int]any)
	ranks := make(map[int]int)
	parents := make(map[int]int)
	withSecret[0] = nil
	withSecret[firstPerson] = nil
	t := 0
	for _, meeting := range meetings {
		if t != meeting[2] {
			t = meeting[2]
			for node, parnet := range parents {
				if _, exists := withSecret[node]; exists {
					continue
				}
				if _, exists := withSecret[parnet]; exists {
					withSecret[node] = nil
				}
			}
			ranks = make(map[int]int)
			parents = make(map[int]int)
		}
		if _, exists := parents[meeting[0]]; !exists {
			parents[meeting[0]] = meeting[0]
			ranks[meeting[0]] = 0
		}
		if _, exists := parents[meeting[1]]; !exists {
			parents[meeting[1]] = meeting[1]
			ranks[meeting[1]] = 0
		}
		union(parents, ranks, meeting[0], meeting[1])
		if _, exists := withSecret[meeting[0]]; exists {
			withSecret[meeting[1]] = nil
			withSecret[parents[meeting[1]]] = nil
		}
		if _, exists := withSecret[meeting[1]]; exists {
			withSecret[meeting[0]] = nil
			withSecret[parents[meeting[0]]] = nil
		}
	}
	for node, parnet := range parents {
		if _, exists := withSecret[node]; exists {
			continue
		}
		if _, exists := withSecret[parnet]; exists {
			withSecret[node] = nil
		}
	}
	for key, _ := range withSecret {
		result = append(result, key)
	}
	return result
}
