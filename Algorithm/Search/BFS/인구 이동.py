import sys
from collections import deque

N, L, R = map(int, sys.stdin.readline().split())
grid = [[] for _ in range(N)]
for i in range(N):
    grid[i] = list(map(int, sys.stdin.readline().split()))
directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def move_population(r, c):
    global total_population
    dq = deque()
    dq.append((r, c))
    visited[r][c] = True
    total_population = grid[r][c]
    neighbor = [(r, c)]
    while dq:
        cur_r, cur_c = dq.popleft()
        for dr, dc in directions:
            nr, nc = cur_r + dr, cur_c + dc
            if 0 <= nr < N and 0 <= nc < N and not visited[nr][nc]:
                if L <= abs(grid[cur_r][cur_c] - grid[nr][nc]) <= R:
                    dq.append((nr, nc))
                    visited[nr][nc] = True
                    total_population += grid[nr][nc]
                    neighbor.append((nr, nc))
    return neighbor

def distribute_population(neighbor):
    global total_population
    neighbor_cnt = len(neighbor)
    for r, c in neighbor:
            grid[r][c] = total_population // neighbor_cnt

cnt = 0
while True:
    flag = False
    visited = [[False] * N for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                neighbor = move_population(i, j)
                if len(neighbor) != 1:
                    flag = True
                    distribute_population(neighbor)
    
    if not flag:
        break
    cnt += 1
print(cnt)

