import sys
from queue import PriorityQueue
V, E = map(int, sys.stdin.readline().split())
K = int(sys.stdin.readline())
distances = [float('inf')] * (V + 1)
visited = [False] * (V + 1)
graph = [[] for _ in range(V + 1)]

for _ in range(E):
    u, v, w = map(int, sys.stdin.readline().split())
    graph[u].append((v, w))

pq = PriorityQueue()
distances[K] = 0
pq.put((0, K))
while pq.qsize() > 0:
    cum, cur = pq.get()
    if visited[cur]:
        continue
    visited[cur] = True
    for nxt, w in graph[cur]:
        if not visited[nxt] and distances[cur] + w < distances[nxt]:
            distances[nxt] = distances[cur] + w
            pq.put((distances[nxt], nxt))

for i in range(1, V + 1):
    if distances[i] == float('inf'):
        print('INF')
    else:
        print(distances[i])