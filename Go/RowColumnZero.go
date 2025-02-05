package main

import "fmt"

func FindInArray(v []int, i int) bool {
	for j := 0; j < len(v); j++ {
		if v[j] == i {
			return true
		}
	}

	return false
}

func SetRowColumnZeroes(matrix [][]int) {
	var rows, cols []int

	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			if matrix[i][j] == 0 {
				if !FindInArray(rows, i) {
					rows = append(rows, i)
				}
				if !FindInArray(cols, j) {
					cols = append(cols, j)
				}
			}
		}
	}

	for i := 0; i < len(rows); i++ {
		for j := 0; j < len(matrix[rows[i]]); j++ {
			matrix[rows[i]][j] = 0
		}
	}

	for i := 0; i < len(cols); i++ {
		for j := 0; j < len(matrix); j++ {
			matrix[j][cols[i]] = 0
		}
	}
}

func main() {
	for {
		fmt.Print("The size of the matrix (columns, rows): ")
		var rows, cols int
		fmt.Scan(&cols, &rows)
		if cols == 0 && rows == 0 {
			break
		}

		matrix := make([][]int, rows)
		for i := 0; i < rows; i++ {
			fmt.Printf("The %dth row: ", i+1)
			matrix[i] = make([]int, cols)
			for j := 0; j < cols; j++ {
				fmt.Scan(&matrix[i][j])
			}
		}

		SetRowColumnZeroes(matrix)

		for i := 0; i < rows; i++ {
			fmt.Print(matrix[i][0])
			for j := 1; j < cols; j++ {
				fmt.Printf(", %d", matrix[i][j])
			}
			fmt.Println(" ")
		}
	}
}
