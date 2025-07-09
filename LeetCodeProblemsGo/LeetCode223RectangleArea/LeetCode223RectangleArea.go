package LeetCode223RectangleArea

func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
	area := 0
	area += (ax2 - ax1) * (ay2 - ay1)
	area += (bx2 - bx1) * (by2 - by1)
	startX := ax1
	if bx1 > ax1 {
		startX = bx1
	}
	endX := ax2
	if bx2 < ax2 {
		endX = bx2
	}
	if endX < startX {
		return area
	}
	startY := ay1
	if by1 > ay1 {
		startY = by1
	}
	endY := ay2
	if by2 < ay2 {
		endY = by2
	}
	if endY < startY {
		return area
	}
	area -= (endX - startX) * (endY - startY)
	return area
}
