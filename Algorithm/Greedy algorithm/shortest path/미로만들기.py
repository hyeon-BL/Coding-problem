# import sys
# from queue import PriorityQueue
# n = int(sys.stdin.readline())
# grid = [sys.stdin.readline() for _ in range(n)]
# distances = [[float('inf')] * n for _ in range(n)]
# visited = [[False] * n for _ in range(n)]
# directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

# pq = PriorityQueue()
# pq.put((0, 0, 0))
# distances[0][0] = 0
# while pq.qsize() > 0:
#     cum, cr, cc = pq.get()
#     visited[cr][cc] = True
#     for dr, dc in directions:
#         nr, nc = dr + cr, dc + cc
#         if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
#             w = abs(int(grid[nr][nc]) - 1)
#             if distances[nr][nc] > cum + w:
#                 distances[nr][nc] = cum + w
#                 pq.put((distances[nr][nc], nr, nc))
# print(distances[n - 1][n - 1])

import sys
from collections import deque
n = int(sys.stdin.readline())
grid = [sys.stdin.readline() for _ in range(n)]
distances = [[float('inf')] * n for _ in range(n)]
visited = [[False] * n for _ in range(n)]
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

dq = deque()
dq.append((0, 0))
distances[0][0] = 0
while dq:
    cr, cc = dq.popleft()
    visited[cr][cc] = True
    for dr, dc in directions:
        nr, nc = dr + cr, dc + cc
        if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
            w = abs(int(grid[nr][nc]) - 1)
            if distances[nr][nc] > distances[cr][cc] + w:
                if w == 0:
                    dq.appendleft((nr, nc))
                else:
                    dq.append((nr, nc))
                distances[nr][nc] = distances[cr][cc] + w
print(distances[n - 1][n - 1])