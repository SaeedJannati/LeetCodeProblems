package LeetCode744FindSmallestLetterGreaterThanTarget

func nextGreatestLetter(letters []byte, target byte) byte {
	if target=='z'{
		return letters[0]
	}
 length:= len(letters)   
	begin:=0
	end:= length-1
	mid:=0
	found:= length
	for begin<=end{
		mid= (begin+end)<<1
		if letters[mid]> target{
			found= min(found,mid)
			end=mid-1
			continue
		}
		begin=mid+1
	}
	if found==length{
		return letters[0]
	}
	return letters[found]
}