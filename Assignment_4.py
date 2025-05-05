def is_safe(board, row, col, n):
    # Check if the column is safe

    for i in range(row):
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True

def solve_n_queens_backtracking(board, row, n):
    if row == n:  # All queens are placed
        return True

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row] = col  # Place queen
            if solve_n_queens_backtracking(board, row + 1, n):
                return True
            board[row] = -1  # Backtrack
    return False

def print_solution(board, n):
    for row in range(n):
        line = ['Q' if board[row] == col else '.' for col in range(n)]
        print(" ".join(line))

def n_queens_backtracking(n):
    board = [-1] * n  # Initialize board
    if solve_n_queens_backtracking(board, 0, n):
        print_solution(board, n)
    else:
        print("Solution does not exist")

# Test for 8 queens
n = int(input("Enter a grid size:"))
n_queens_backtracking(n)
