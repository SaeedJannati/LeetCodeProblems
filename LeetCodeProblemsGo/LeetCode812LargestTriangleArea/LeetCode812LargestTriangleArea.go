package LeetCode812LargestTriangleArea

func largestTriangleArea(points [][]int) float64 {
	length := len(points)
	var area float64
	var maxArea float64
	first := make([]float64, 2)
	second := make([]float64, 2)
	for i := 0; i < length-2; i++ {
		for j := i + 1; j < length-1; j++ {
			for k := j + 1; k < length; k++ {
				first[0], first[1] = float64(points[i][0]-points[j][0]), float64(points[i][1]-points[j][1])
				second[0], second[1] = float64(points[i][0]-points[k][0]), float64(points[i][1]-points[k][1])
				area = .5 * (first[0]*second[1] - first[1]*second[0])
				if area < 0 {
					area = -area
				}
				if area > maxArea {
					maxArea = area
				}

			}
		}
	}
	return maxArea
}
