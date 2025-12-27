import sys
sys.setrecursionlimit(10000) # overflow prevention

N, M = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

connected_components = 0
visited = [False] * (N + 1)

def dfs(node):
    visited[node] = True
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor)

for i in range(1, N + 1):
    if not visited[i]:
        dfs(i)
        connected_components += 1

print(connected_components)