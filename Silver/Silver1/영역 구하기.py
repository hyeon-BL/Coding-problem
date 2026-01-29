import sys
sys.setrecursionlimit(100000)

M, N, K = map(int, sys.stdin.readline().split())
grid = [['0'] * (N) for _ in range(M)]
dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]

for _ in range(K):
	bl_x, bl_y, tr_x, tr_y = map(int, sys.stdin.readline().split())
	for i in range(M - bl_y - 1, M - tr_y - 1, -1):
		for j in range(bl_x, tr_x):
			grid[i][j] = '1'

def dfs(i, j):
	global cnt, M, N
	grid[i][j] = '1'
	for dx, dy in dir:
		nx, ny = dx + j, dy + i
		if 0 <= nx < N and 0 <= ny < M and grid[ny][nx] == '0':
			dfs(ny, nx)
			cnt += 1

areas = []
for i in range(M):
	for j in range(N):
		if grid[i][j] == '0':
			cnt = 1
			dfs(i, j)
			areas.append(cnt)
areas.sort()
print(len(areas))
print(' '.join(map(str, areas)))
