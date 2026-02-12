import sys
from collections import deque
N = int(sys.stdin.readline())
frm, to = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(N + 1)]
relations = int(sys.stdin.readline())
for _ in range(relations):
	a, b = map(int, sys.stdin.readline().split())
	graph[a].append(b)
	graph[b].append(a)

dq = deque()
visited = [False] * (N + 1)
dq.append((frm, 0))
while dq:
	cur, cnt = dq.popleft()
	visited[cur] = True

	if cur == to:
		print(cnt)
		break

	for nxt in graph[cur]:
		if not visited[nxt]:
			dq.append((nxt, cnt + 1))
else:
	print(-1)
