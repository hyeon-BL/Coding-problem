import sys
import heapq
from collections import deque
R, C = map(int, sys.stdin.readline().split())
grid = []
edges = []
directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]
visited = [[False] * C for _ in range(R)]

# Step 1. Grid -> Graph (edge list)
for _ in range(R):
    row = list(map(int, sys.stdin.readline().split()))
    grid.append(row)

def bfs(start, mark):
    global R, C
    q = deque()
    visited[start[0]][start[1]] = True
    q.append((start[0], start[1]))
    while q:
        cur = q.popleft()
        grid[cur[0]][cur[1]] = mark
        for dr, dc in directions:
            nxtR, nxtC = (cur[0] + dr, cur[1] + dc)
            if 0 <= nxtR < R and 0 <= nxtC < C and grid[nxtR][nxtC] and not visited[nxtR][nxtC]:
                q.append((nxtR, nxtC))
                visited[nxtR][nxtC] = True

def init():
    global R, C
    cnt = 1
    for i in range(R):
        for j in range(C):
            if grid[i][j] and not visited[i][j]:
                bfs((i, j), cnt)
                cnt += 1

    for i in range(R):
        for j in range(C):
            curMark = grid[i][j]
            if curMark:
                for dr, dc in directions:
                    leng = 0
                    nxtR, nxtC = i + dr, j + dc
                    while 0 <= nxtR < R and 0 <= nxtC < C:
                        nxtMark = grid[nxtR][nxtC]
                        if curMark == nxtMark:
                            break
                        elif nxtMark:
                            if leng > 1:
                                heapq.heappush(edges, (leng, curMark, nxtMark))
                            break
                        nxtR += dr
                        nxtC += dc
                        if not nxtMark: # 바다인 경우
                            leng += 1
    return cnt - 1

# Step 2. MST
V = init()
parents = [i for i in range(V + 1)]

def find(a):
    if parents[a] != a:
        parents[a] = find(parents[a])
    return parents[a]

def union(a, b):
    rootA = find(a)
    rootB = find(b)
    if rootA != rootB:
        parents[rootB] = rootA

edgeCnt = 0
minLen = 0
m = []
while edges and edgeCnt < V - 1:
    w, u, v = heapq.heappop(edges)
    if find(u) != find(v):
        union(u, v)
        minLen += w
        edgeCnt += 1
        m.append((u, v, w))

if edges:
    print(minLen)
else:
    print(-1)