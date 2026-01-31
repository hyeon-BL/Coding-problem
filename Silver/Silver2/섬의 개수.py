import sys
sys.setrecursionlimit(10**6)
directions = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]

def dfs(i, j):
	global w, h
	grid[i][j] = 0
	for dy, dx in directions:
		ny, nx = dy + i, dx + j
		if (0 <= ny < h and 0 <= nx < w and grid[ny][nx]):
			dfs(ny, nx)

while True:
	w, h = map(int, sys.stdin.readline().split())
	if (w == 0 and h == 0):
		break

	grid = []
	for _ in range(h):
		row = list(map(int, sys.stdin.readline().split()))
		grid.append(row)
	cnt = 0
	for i in range(h):
		for j in range(w):
			if grid[i][j]:
				cnt += 1
				dfs(i, j)
	print(cnt)
