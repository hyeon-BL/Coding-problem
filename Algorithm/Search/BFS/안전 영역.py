import sys
from collections import deque

N = int(sys.stdin.readline())
grid = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def bfs(start, sink):
    if visited[start[0]][start[1]]:
        return False

    q = deque()
    q.append(start)
    visited[start[0]][start[1]] = True

    while q:
        cur_R, cur_C = q.popleft()
        for dir_R, dir_C in dir:
            next_R = cur_R + dir_R
            next_C = cur_C + dir_C
            if 0 <= next_R < N and 0 <= next_C < N and not visited[next_R][next_C] and grid[next_R][next_C] > sink:
                q.append((next_R, next_C))
                visited[next_R][next_C] = True
    return True

max_area = 0
max_height = 0
for row in grid:
    max_height = max(max_height, max(row))

for sink in range(0, max_height):
    visited = [[False] * N for _ in range(N)]
    region = 0
    for i in range(N):
        for j in range(N):
            if grid[i][j] > sink and bfs((i, j), sink):
                region += 1
    max_area = max(max_area, region)
print(max_area)