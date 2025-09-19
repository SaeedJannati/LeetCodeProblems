package LeetCode3484DesignSpreadsheet

type Spreadsheet struct {
	row    int
	column int
	sheet  [][]int
}

func isCellString(input string) bool {
	return input[0] >= 'A' && input[0] <= 'Z'
}
func (this *Spreadsheet) fillCellInfo(cell string) {
	this.row = int(cell[0] - 'A')
	this.column = 0
	for i, e := 1, len(cell); i < e; i++ {
		this.column *= 10
		this.column += int(cell[i] - '0')
	}
	this.column--
}
func (this *Spreadsheet) calculateValue(input string) int {
	if isCellString(input) {
		this.fillCellInfo(input)
		return this.sheet[this.row][this.column]
	}
	value := 0
	for _, c := range input {
		value *= 10
		value += int(c - '0')
	}
	return value
}
func Constructor(rows int) Spreadsheet {
	sheet := Spreadsheet{}
	sheet.sheet = make([][]int, 26)
	for i := 0; i < 26; i++ {
		sheet.sheet[i] = make([]int, rows)
	}
	return sheet
}

func (this *Spreadsheet) SetCell(cell string, value int) {
	this.fillCellInfo(cell)
	this.sheet[this.row][this.column] = value
}

func (this *Spreadsheet) ResetCell(cell string) {
	this.SetCell(cell, 0)
}

func (this *Spreadsheet) GetValue(formula string) int {
	value := 0
	raw := []byte{}
	for i, e := 1, len(formula); i < e; i++ {
		if formula[i] == '+' {
			value = this.calculateValue(string(raw))
			raw = []byte{}
			continue
		}
		raw = append(raw, formula[i])
	}
	value += this.calculateValue(string(raw))
	return value
}
