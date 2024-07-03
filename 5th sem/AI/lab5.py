def is_safe(board, row, col, N):
    # Check if there is a queen in the same column up to the current row
    for i in range(row):
        if board[i][col] == 1:
            return False
    
    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    # Check upper diagonal on right side
    for i, j in zip(range(row, -1, -1), range(col, N)):
        if board[i][j] == 1:
            return False
    
    return True

def solve_n_queens_util(board, row, N, result):
    # If all queens are placed then add the solution to result
    if row == N:
        result.append(["".join("Q" if cell == 1 else "." for cell in row) for row in board])
        return
    
    for col in range(N):
        if is_safe(board, row, col, N):
            board[row][col] = 1
            solve_n_queens_util(board, row + 1, N, result)
            board[row][col] = 0  # Backtrack

def solve_n_queens(N):
    board = [[0] * N for _ in range(N)]
    result = []
    solve_n_queens_util(board, 0, N, result)
    return result

def print_solutions(solutions):
    for i, solution in enumerate(solutions):
        print(f"Solution {i+1}:")
        for row in solution:
            print(row)
        print()

if __name__ == "__main__":
    N = 4  # Change N to the desired board size
    solutions = solve_n_queens(N)
    print_solutions(solutions)
