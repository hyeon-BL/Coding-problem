import sys
from collections import deque
N = int(sys.stdin.readline())
graph = [[] for _ in range(N + 1)]

while True:
	a, b = map(int, sys.stdin.readline().split())
	if a == -1 and b == -1:
		break
	graph[a].append(b)
	graph[b].append(a)

def bfs(node):
	dq = deque()
	visited = [False] * (N + 1)
	dq.append((node, 0))
	while dq:
		cur, cur_l = dq.popleft()
		visited[cur] = True

		if visited.count(True) == N:
			return cur_l

		for nxt in graph[cur]:
			if not visited[nxt]:
				dq.append((nxt, cur_l + 1))
	return cur_l

shortest = float('inf')
candidates = []
for i in range(1, N + 1):
	current = bfs(i)
	if shortest > current:
		candidates.clear()
		candidates.append(i)
		shortest = current
	elif shortest == current:
		candidates.append(i)
	else:
		continue
print(shortest, len(candidates))
print(*sorted(candidates))
