import sys
from collections import deque
N, M = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N + 1)]
indegree = [0] * (N + 1)

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    indegree[v] += 1

dq = deque()
for i in range(1, N + 1):
    if indegree[i] == 0:
        dq.append(i)

while dq:
    cur = dq.popleft()
    print(cur, end=' ')
    for nxt in graph[cur]:
        indegree[nxt] -= 1
        if indegree[nxt] == 0:
            dq.append(nxt)