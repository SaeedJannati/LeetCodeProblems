package LeetCode2171RemovingMinimumNumberOfMagicBeans

import (
	"slices"
)

func minimumRemoval(beans []int) int64 {
	slices.Sort(beans)
	length := len(beans)
	result := int64(1<<63 - 1)
	var sum int64 = 0
	for _, bean := range beans {
		sum += int64(bean)
	}
	for i, bean := range beans {
		result = min(result, sum-int64(length-i)*int64(bean))
	}
	return result
}
