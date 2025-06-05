package LeetCode1061LexicographicallySmallestEquivalentString

func find(parents []byte, char byte) byte {
	if parents[char] == char {
		return char
	}
	parents[char] = find(parents, parents[char])
	return parents[char]
}
func union(parents []byte, first, second byte) {
	firstParent := find(parents, first)
	secondParent := find(parents, second)
	if firstParent == secondParent {
		return
	}
	if firstParent < secondParent {
		parents[secondParent] = firstParent
		find(parents, second)
		return
	}
	parents[firstParent] = secondParent
	find(parents, first)

}
func smallestEquivalentString(s1 string, s2 string, baseStr string) string {
	parents := make([]byte, 26)
	for i := 0; i < 26; i++ {
		parents[i] = byte(i)
	}
	var lowerA byte = 'a'
	length := len(s1)
	for i := 0; i < length; i++ {
		union(parents, s1[i]-lowerA, s2[i]-lowerA)
	}
	baseLength := len(baseStr)
	reulst := make([]byte, baseLength)
	for i, e := 0, len(baseStr); i < e; i++ {
		reulst[i] = find(parents, baseStr[i]-lowerA) + lowerA
	}
	return string(reulst)
}
