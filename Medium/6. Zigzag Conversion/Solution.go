func convert(s string, numRows int) string {
    if numRows == 1 || numRows >= len(s) {
        return s
    }

    rows := make([]string, numRows)
    currentRow := 0
    goingDown := false

    for _, char := range s {
        rows[currentRow] += string(char)
        
        // Change direction when we hit the top or bottom row
        if currentRow == 0 || currentRow == numRows-1 {
            goingDown = !goingDown
        }
        
        if goingDown {
            currentRow += 1
        } else {
            currentRow -= 1
        }
    }

    // Combine all rows into a single string
    result := ""
    for _, row := range rows {
        result += row
    }

    return result
}
