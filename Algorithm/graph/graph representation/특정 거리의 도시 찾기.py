import sys
from collections import deque
N, M, K, X = map(int, sys.stdin.readline().split())
adj = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    adj[u].append(v)

dq = deque()
dist = 0
dist_K = []

dq.append((X, dist))
visited[X] = True
while dq:
    cur, dist = dq.popleft()

    if dist == K:
        dist_K.append(cur)
        continue

    for next in adj[cur]:
        if not visited[next]:
            dq.append((next, dist + 1))
            visited[next] = True

if len(dist_K) == 0:
    print(-1)
else:
    dist_K.sort()
    for ele in dist_K: print(ele)