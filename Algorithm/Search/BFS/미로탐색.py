import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
grid = [sys.stdin.readline().strip() for _ in range(N)]
dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]

q = deque()
start = (0, 0)
visited = [[0] * M for _ in range(N)]
q.append(start)
visited[start[0]][start[1]] = 1

while q:
    cur_l, cur_r = q.popleft()

    for ld, rd in dir:
        next_l = cur_l + ld
        next_r = cur_r + rd
        if 0 <= next_l <= N - 1 and 0 <= next_r <= M - 1 and not visited[next_l][next_r] and int(grid[next_l][next_r]):
            q.append((next_l, next_r))
            visited[next_l][next_r] = visited[cur_l][cur_r] + 1

print(visited[N - 1][M - 1]) 