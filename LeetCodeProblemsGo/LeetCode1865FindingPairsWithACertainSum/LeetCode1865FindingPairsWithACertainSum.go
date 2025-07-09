package LeetCode1865FindingPairsWithACertainSum

import "sort"

type FindSumPairs struct {
	nums2Map map[int]int
	nums1    []int
	nums2    []int
}

func Constructor(nums1 []int, nums2 []int) FindSumPairs {

	sort.Ints(nums1)
	m := make(map[int]int, len(nums2))
	for _, num := range nums2 {
		m[num]++
	}
	return FindSumPairs{nums1: nums1, nums2: nums2, nums2Map: m}
}

func (this *FindSumPairs) Add(index int, val int) {
	this.nums2Map[this.nums2[index]]--
	this.nums2[index] += val
	this.nums2Map[this.nums2[index]]++
}

func (this *FindSumPairs) Count(tot int) int {
	result := 0
	for _, num := range this.nums1 {
		if num >= tot {
			break
		}
		if value, exists := this.nums2Map[tot-num]; exists {
			result += value
		}
	}
	return result
}
