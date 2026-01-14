import sys
sys.setrecursionlimit(100000)
N = int(sys.stdin.readline())
adj = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)
parents = [0] * (N + 1)

for _ in range(N - 1):
    u, v = map(int, sys.stdin.readline().split())
    adj[u].append(v)
    adj[v].append(u)

def dfs(node, parent):
    parents[node] = parent
    visited[node] = True
    for nxt in adj[node]:
        if not visited[nxt]:
            dfs(nxt, node)

dfs(1, 0)
for i in range(2, N + 1):
    print(parents[i])
