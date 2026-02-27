import sys
from queue import PriorityQueue
M, N = map(int, sys.stdin.readline().split())
grid = [sys.stdin.readline().rstrip() for _ in range(N)]
distances = [[float('inf')] * M for _ in range(N)]
visited = [[False] * M for _ in range(N)]
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

pq = PriorityQueue()
pq.put((0, 0, 0))
distances[0][0] = 0
while pq.qsize() > 0:
    cum, cr, cc = pq.get()
    if visited[cr][cc]:
        continue
    visited[cr][cc] = True
    for dr, dc in directions:
        nr, nc = dr + cr, dc + cc
        if 0 <= nr < N and 0 <= nc < M and not visited[nr][nc] and distances[nr][nc] > distances[cr][cc] + int(grid[nr][nc]):
            distances[nr][nc] = distances[cr][cc] + int(grid[nr][nc])
            pq.put((distances[nr][nc], nr, nc))

print(distances[N - 1][M - 1])