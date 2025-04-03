package LeetCode81SearchInRotatedSortedArrayII

func search(nums []int, target int) bool {
	length := len(nums)
	next := 0
	previous := 0
	begin := 0
	end := length - 1
	mid := 0
	found := false
	for begin <= end {
		mid = (begin + end) / 2
		next = getNextRecursive(nums, mid, length)
		if next == mid {
			return nums[mid] == target
		}
		previous = getPreviousRecursive(nums, mid, length)
		if previous == mid {
			return nums[mid] == target
		}
		if previous == next {
			return target == nums[mid] || target == nums[next]
		}
		if target == nums[mid] {
			return true
		}
		if nums[mid] < nums[previous] && nums[mid] < nums[next] {
			mid = getNextRecursive(nums, previous, length)
			found = true
			break
		}
		if nums[mid] > nums[length-1] {
			begin = mid + 1
			continue
		}
		end = mid - 1
	}
	if !found {
		previous = getPreviousRecursive(nums, mid, length)
		next = getNextRecursive(nums, mid, length)
		if nums[mid] > nums[previous] {
			mid = previous
		} else if nums[mid] > nums[next] {
			mid = next
		}
	}
	if target == nums[mid] {
		return true
	}
	if mid != length-1 && target > nums[mid] && target <= nums[length-1] {
		begin = mid
		end = length - 1
		for begin <= end {
			mid = (begin + end) / 2
			if nums[mid] == target {
				return true
			}
			if nums[mid] > target {
				end = mid - 1
				continue
			}
			begin = mid + 1
		}
		return false
	}
	if mid == 0 {
		return false
	}
	begin = 0
	end = mid - 1
	for begin <= end {
		mid = (begin + end) / 2
		if nums[mid] == target {
			return true
		}
		if nums[mid] > target {
			end = mid - 1
			continue
		}
		begin = mid + 1
	}
	return false
}
func getNextRecursive(nums []int, index int, length int) int {
	next := index
	for nums[index] == nums[next] {
		next = getNext(length, next)
		if next == index {
			return index
		}
	}
	return next
}

func getPreviousRecursive(nums []int, index int, length int) int {
	previous := index
	for nums[previous] == nums[index] {
		previous = getPrevious(length, previous)
		if previous == index {
			return index
		}
	}
	return previous
}
func getNext(length int, index int) int {
	if index < length-1 {
		return index + 1
	}
	return 0
}
func getPrevious(length int, index int) int {
	if index > 0 {
		return index - 1
	}
	return length - 1
}
