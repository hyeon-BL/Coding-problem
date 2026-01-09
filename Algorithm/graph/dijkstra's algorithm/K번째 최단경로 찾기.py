import sys
import heapq
N, M, K = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N + 1)]
distances = [[float('inf')] * K for _ in range(N + 1)]

for _ in range(M):
    u, v, w = map(int, sys.stdin.readline().split())
    graph[u].append((v, w))

pq = []
distances[1][0] = 0 # 시작노드의 0번째 최단거리
heapq.heappush(pq, (distances[1][0], 1))

while pq:
    dis, cur = heapq.heappop(pq)
    for nxt, w in graph[cur]:
        new_dis = dis + w
        if distances[nxt][K - 1] > new_dis:
            distances[nxt][K - 1] = new_dis
            distances[nxt].sort() # 0, 1, 2 ... K - 1번까지 거리 순서대로 쌓임
            heapq.heappush(pq, (new_dis, nxt))

for i in range(1, N + 1):
    if distances[i][K - 1] == float('inf'):
        print(-1)
    else:
        print(distances[i][K - 1])