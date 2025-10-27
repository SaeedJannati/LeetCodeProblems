package LeetCode2125NumberOfLaserBeamsInABank

func numberOfBeams(bank []string) int {
	beamsCount := 0
	previousRowDevices := 0
	currentRowDevices := 0
	for _, row := range bank {
		currentRowDevices = 0
		for _, char := range row {
			if char == '1' {
				currentRowDevices++
			}
		}
		if currentRowDevices == 0 {
			continue
		}
		beamsCount += previousRowDevices * currentRowDevices
		previousRowDevices = currentRowDevices
	}
	return beamsCount
}
