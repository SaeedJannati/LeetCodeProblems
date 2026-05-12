package LeetCode1665MinimumInitialEnergyToFinishTasks

import "sort"

func minimumEffort(tasks [][]int) int {
	sort.Slice(tasks, func(i, j int) bool {
		if tasks[i][1]-tasks[i][0] != tasks[j][1]-tasks[j][0] {
			return tasks[i][1]-tasks[i][0] > tasks[j][1]-tasks[j][0]
		}
		return tasks[i][0] > tasks[j][0]
	})
	current, delta, used := 0, 0, 0
	for _, task := range tasks {
		if current < task[1] {
			delta = task[1] - current
			current += delta
			used += delta
		}
		current -= task[0]

	}
	return used
}
