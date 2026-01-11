import sys
N, M = map(int ,sys.stdin.readline().split())
friends = [[float('inf')] * (N + 1) for _ in range(N + 1)]

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    friends[u][v] = 1
    friends[v][u] = 1

for i in range(1, N + 1):
    friends[i][i] = 0

for K in range(1, N + 1):
    for S in range(1, N + 1):
        for E in range(1, N + 1):
            if friends[S][E] > friends[S][K] + friends[K][E]:
                friends[S][E] = friends[S][K] + friends[K][E]

min_sum = float('inf')
min_idx = 0
for i in range(1, N + 1):
    temp = sum(friends[i][1:])
    if temp < min_sum:
        min_sum = temp
        min_idx = i

print(min_idx)