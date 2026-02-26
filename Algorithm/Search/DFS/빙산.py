import sys
sys.setrecursionlimit(10**4)

N, M = map(int, sys.stdin.readline().split())
grid = [[] for _ in range(N)]
for i in range(N):
    grid[i] = list(map(int, sys.stdin.readline().split()))

directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
visited = [[False] * M for _ in range(N)]
def time_goes():
    minus = [[0] * M for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 0: continue
            waters = 0
            for dr, dc in directions:
                nr, nc = dr + i, dc + j
                if 0 <= nr < N and 0 <= nc < M and grid[nr][nc] == 0:
                    waters += 1
            minus[i][j] = waters
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 0: continue
            grid[i][j] = max(0, grid[i][j] - minus[i][j])

def is_separated():
    global visited
    cnt = 0
    visited = [[False] * M for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if grid[i][j] > 0 and not visited[i][j]:
                dfs((i, j))
                cnt += 1
    return cnt
   
def dfs(cur):
    r, c = cur
    visited[r][c] = True
    for dr, dc in directions:
        nr, nc = dr + r, dc + c
        if 0 <= nr < N and 0 <= nc < M and not visited[nr][nc] and grid[nr][nc] > 0:
            dfs((nr, nc))

times = 0
while is_separated() == 1:
    time_goes()
    times += 1
if is_separated() > 1:
    print(times)
else:
    print(0)