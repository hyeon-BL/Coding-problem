import sys
from collections import deque
N, M = map(int, sys.stdin.readline().split())
grid = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def bfs(start):
    dq = deque()
    dq.append(start)
    visited[start[0]][start[1]] = True
    area = 1
    while dq:
        cur_r, cur_c = dq.popleft()
        for d_r, d_c in directions:
            n_r, n_c = cur_r + d_r, cur_c + d_c
            if 0 <= n_r < N and 0 <= n_c < M and grid[n_r][n_c] and not visited[n_r][n_c]:
                area += 1
                visited[n_r][n_c] = True
                dq.append((n_r, n_c))
    return area

cnt = 0
max_area = 0
for i in range(N):
    for j in range(M):
        if grid[i][j] and not visited[i][j]:
            cnt += 1
            max_area = max(max_area, bfs((i, j)))
print(cnt)
print(max_area)