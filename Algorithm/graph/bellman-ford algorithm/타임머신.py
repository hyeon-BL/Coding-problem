import sys
N, M = map(int, sys.stdin.readline().split())
edges = [] # full edge information
distances = [float('inf')] * (N + 1)

for _ in range(M):
    u, v, w = map(int, sys.stdin.readline().split())
    edges.append((u, v, w))

distances[1] = 0 # 출발 노드 초기화
for _ in range(N - 1): # (노드 수 - 1)번 반복
    for start, end, t in edges: # edge 수만큼 반복
        if distances[start] != float('inf') and distances[end] > distances[start] + t:
            distances[end] = distances[start] + t

negative_cycle = False
for start, end, t in edges:
    if distances[start] != float('inf') and distances[end] > distances[start] + t:
        negative_cycle = True
        break

if negative_cycle:
    print(-1)
else:
    for i in range(2, N + 1):
        if distances[i] == float('inf'):
            print(-1)
        else:
            print(distances[i])