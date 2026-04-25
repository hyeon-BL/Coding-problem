import sys
from collections import deque
N = int(sys.stdin.readline())
grid = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def mk_island():
    num = 2
    for i in range(N):
        for j in range(N):
            if grid[i][j] == 1:
                dq = deque()
                dq.append((i, j))
                grid[i][j] = num
                while dq:
                    cur_r, cur_c = dq.popleft()

                    for dr, dc in directions:
                        nxt_r, nxt_c = cur_r + dr, cur_c + dc
                        if 0 <= nxt_r < N and 0 <= nxt_c < N and grid[nxt_r][nxt_c] == 1:
                            dq.append((nxt_r, nxt_c))
                            grid[nxt_r][nxt_c] = num
                num += 1
    return num

def shortest_path(start_num):
    dist = [[-1] * N for _ in range(N)]
    dq = deque()

    for i in range(N):
        for j in range(N):
            if grid[i][j] == start_num:
                dist[i][j] = 0
                dq.append((i, j))

    while dq:
        r, c = dq.popleft()
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < N:
                if grid[nr][nc] != 0 and grid[nr][nc] != start_num:
                    return dist[r][c]
                
                if grid[nr][nc] == 0 and dist[nr][nc] == -1:
                    dist[nr][nc] = dist[r][c] + 1
                    dq.append((nr, nc))
    return float('inf')

total_islands = mk_island()
min_len = float('inf')

for num in range(2, total_islands):
    min_len = min(min_len, shortest_path(num))

print(min_len)