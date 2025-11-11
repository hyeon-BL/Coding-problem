import sys
N, M = map(int, sys.stdin.readline().split())
boards = [list(map(int, sys.stdin.readline().strip())) for _ in range(N)]

def flip(board, x, y):
    for i in range(x + 1):
        for j in range(y + 1):
            board[i][j] = 1 - board[i][j]

count = 0
for i in range(N - 1, -1, -1):
    for j in range(M - 1, -1, -1):
        if boards[i][j] == 1:
            flip(boards, i, j)
            count += 1

print(count)