import sys
sys.setrecursionlimit(10**5)
N, M = map(int, sys.stdin.readline().split())
grid = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

removed = [(0, 0)]
def dfs(r, c):
    for dr, dc in directions:
        nr, nc = r + dr, c + dc
        if 0 <= nr < N and 0 <= nc < M and not visited[nr][nc] and grid[nr][nc] == 0:
            visited[nr][nc] = True
            dfs(nr, nc)
        if 0 <= nr < N and 0 <= nc < M and not visited[nr][nc] and grid[nr][nc] == 1:
            removed.append((nr, nc))
            visited[nr][nc] = True


def all_removed():
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 1:
                return False
    return True

time = 0
remained = 0
while True:
    visited = [[False] * M for _ in range(N)]
    while removed:
        r, c = removed.pop()
        grid[r][c] = 0

    if all_removed():
        break
    
    dfs(r, c)
    time += 1
    remained = len(removed)
print(time)
print(remained) 
