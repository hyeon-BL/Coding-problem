import sys
sys.setrecursionlimit(10**6)

N = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
dp = [[0] * N for _ in range(N)]
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def dfs(r, c):
	if dp[r][c]:
		return dp[r][c]
	dp[r][c] = 1
	for dr, dc in directions:
		nr, nc = r + dr, c + dc
		if 0 <= nr < N and 0 <= nc < N and arr[nr][nc] > arr[r][c]:
			dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1)
	return dp[r][c]

max_move = 0
for i in range(N):
	for j in range(N):
		max_move = max(max_move, dfs(i, j))
print(max_move)

