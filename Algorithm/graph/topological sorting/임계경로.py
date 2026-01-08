import sys
from collections import deque
N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
A = [[] for _ in range(N + 1)]; reversed_A = [[] for _ in range(N + 1)]
indegree = [0] * (N + 1)

for _ in range(M):
    u, v, w = map(int, sys.stdin.readline().split())
    A[u].append((v, w))
    reversed_A[v].append((u, w))
    indegree[v] += 1

start, end = map(int, sys.stdin.readline().split())

dq = deque()
dq.append(start)
times = [0] * (N + 1)

while dq:
    cur = dq.popleft()
    for nxt, t in A[cur]:
        indegree[nxt] -= 1
        times[nxt] = max(times[nxt], times[cur] + t)
        if indegree[nxt] == 0:
            dq.append(nxt)
dq.clear()

straight_count = 0
visited = [False] * (N + 1)
dq.append(end)
visited[end] = True

while dq:
    cur = dq.popleft()
    for nxt, t in reversed_A[cur]: # 역추적
        if times[nxt] + t == times[cur]: # 가장 오래걸리는 경로
            straight_count += 1
            if not visited[nxt]:
                visited[nxt] = True
                dq.append(nxt)

print(times[end])
print(straight_count)