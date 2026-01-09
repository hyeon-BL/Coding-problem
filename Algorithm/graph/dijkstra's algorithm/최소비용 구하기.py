import sys
from queue import PriorityQueue
N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
graph = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)
distances = [float('inf')] * (N + 1)

for _ in range(M):
    u, v, w = map(int, sys.stdin.readline().split())
    graph[u].append((v, w))

start, end = map(int, sys.stdin.readline().split())

pq = PriorityQueue()
distances[start] = 0
pq.put((distances[start], start))

while pq.qsize() > 0:
    cost, cur = pq.get()
    if visited[cur]: # early stopping
        continue
    visited[cur] = True
    for nxt, w in graph[cur]:
        if not visited[nxt] and distances[nxt] > cost + w:
            distances[nxt] = cost + w
            pq.put((distances[nxt], nxt))

print(distances[end])