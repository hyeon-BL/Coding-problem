import sys
N = int(sys.stdin.readline())
matrix = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
visited = [False] * N
min_cost = float('inf')
START = 0

def backtrack(node, s, cnt):
	global min_cost

	if s >= min_cost:
		return
	if cnt == N:
		if matrix[node][START] != 0:
			min_cost = min(min_cost, s + matrix[node][START])
		return

	for i in range(N):
		if not visited[i] and matrix[node][i] != 0:
			visited[i] = True
			backtrack(i, s + matrix[node][i], cnt + 1)
			visited[i] = False

visited[START] = True
backtrack(START, 0, 1)
print(min_cost)
