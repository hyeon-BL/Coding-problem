import sys
N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
distances = [[float('inf')] * (N + 1) for _ in range(N + 1)] # adjacency matrix

for _ in range(M):
    u, v, w = map(int, sys.stdin.readline().split())
    if distances[u][v] > w: # 작은 비용을 가진 edge만 keep
        distances[u][v] = w

for i in range(N + 1):
    distances[i][i] = 0

for K in range(1, N + 1): # mid
    for S in range(1, N + 1): # start
        for E in range(1, N + 1): # end
            distances[S][E] = min(distances[S][E], distances[S][K] + distances[K][E])

for i in range(1, N + 1):
    for j in range(1, N + 1):
        if distances[i][j] == float('inf'):
            print(0, end=' ')
        else:
            print(distances[i][j], end=' ')
    print()