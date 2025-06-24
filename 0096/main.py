def isSafe(mat, row, col, num):
    for x in range(9):
        if mat[row][x] == num:
            return False

    for x in range(9):
        if mat[x][col] == num:
            return False

    startRow = row - (row % 3)
    startCol = col - (col % 3)

    for i in range(3):
        for j in range(3):
            if mat[i + startRow][j + startCol] == num:
                return False

    return True


def solveSudokuRec(mat, row, col):
    if row == 8 and col == 9:
        return True

    if col == 9:
        row += 1
        col = 0

    if mat[row][col] != 0:
        return solveSudokuRec(mat, row, col + 1)

    for num in range(1, 10):
        if isSafe(mat, row, col, num):
            mat[row][col] = num
            if solveSudokuRec(mat, row, col + 1):
                return True
            mat[row][col] = 0

    return False


def solveSudoku(mat):
    solveSudokuRec(mat, 0, 0)


s = 0
with open("p096_sudoku.txt", "r") as f:
    lines = f.readlines()
    lines = [line.strip() for line in lines if line.strip()]
    lines = [line for line in lines if not line.startswith("Grid")]
    for i in range(50):
        mat = []
        for j in range(9):
            mat.append([int(x) for x in lines[i * 9 + j]])
        solveSudoku(mat)
        s += mat[0][0] * 100 + mat[0][1] * 10 + mat[0][2]

print(s)
