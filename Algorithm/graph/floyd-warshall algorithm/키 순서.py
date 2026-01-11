import sys
N, M = map(int, sys.stdin.readline().split())
adj = [[0] * (N + 1) for _ in range(N + 1)]
rev_adj = [[0] * (N + 1) for _ in range(N + 1)]

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    adj[u][v] = 1
    rev_adj[v][u] = 1

for K in range(1, N + 1):
    for S in range(1, N + 1):
        for E in range(1, N + 1):
            if adj[S][E] == 0 and adj[S][K] == 1 and adj[K][E] == 1:
                adj[S][E] = 1
            if rev_adj[S][E] == 0 and rev_adj[S][K] == 1 and rev_adj[K][E] == 1:
                rev_adj[S][E] = 1

cnt = 0
for i in range(1, N + 1):
    higher = sum(adj[i])
    lower = sum(rev_adj[i])
    if higher + lower == N - 1:
        cnt += 1
print(cnt)
