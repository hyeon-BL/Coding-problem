import sys
N, M = map(int, sys.stdin.readline().split())

visited = [[False] * N for _ in range(M)]
current = (M - 1, 0)  # start at bottom-left corner
directions = [(0, 1), (-1, 0), (0, -1), (1, 0)]  # right, up, left, down
direction_index = 0  # start moving right

while True:
    visited[current[0]][current[1]] = True
    next_row = current[0] + directions[direction_index][0]
    next_col = current[1] + directions[direction_index][1]

    if 0 <= next_row < M and 0 <= next_col < N and not visited[next_row][next_col]:
        current = (next_row, next_col)
    else:
        direction_index = (direction_index + 1) % 4
        next_row = current[0] + directions[direction_index][0]
        next_col = current[1] + directions[direction_index][1]
        if 0 <= next_row < M and 0 <= next_col < N and not visited[next_row][next_col]:
            current = (next_row, next_col)
        else:
            break

print(current[1], M - 1 - current[0])