package LeetCode840MagicSquaresInGrid

func numMagicSquaresInside(grid [][]int) int {
	numsMap := make(map[int]any)
	heigth := len(grid)
	width := len(grid[0])
	result := 0
	for i := 1; i < heigth-1; i++ {
		for j := 1; j < width-1; j++ {
			if grid[i][j] != 5 {
				continue
			}
			numsMap = map[int]any{}
			isMagic := true
			for k := 0; k < 3; k++ {
				for l := 0; l < 3; l++ {
					if grid[i-1+k][j-1+l] > 9 {
						isMagic = false
						break
					}
					numsMap[grid[i-1+k][j-1+l]] = nil
				}
				if !isMagic {
					break
				}
			}
			if !isMagic {
				continue
			}
			if len(numsMap) != 9 {
				continue
			}
			if grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1] != 15 {
				continue
			}
			if grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1] != 15 {
				continue
			}
			if grid[i-1][j-1]+grid[i][j-1]+grid[i+1][j-1] != 15 {
				continue
			}
			if grid[i-1][j+1]+grid[i][j+1]+grid[i+1][j+1] != 15 {
				continue
			}
			if grid[i-1][j-1]+grid[i][j]+grid[i+1][j+1] != 15 {
				continue
			}
			if grid[i-1][j+1]+grid[i][j]+grid[i+1][j-1] != 15 {
				continue
			}

			result++
		}
	}
	return result
}
