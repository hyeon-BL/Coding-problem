import sys
sys.setrecursionlimit(10000)

N, M = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

cnt = 0
visited = [False] * (N + 1)

def dfs(node, depth):
    global cnt
    if depth == 5:
        cnt += 1
        return
    for neighbor in graph[node]:
        if not visited[neighbor]:
            visited[neighbor] = True
            dfs(neighbor, depth + 1)
            visited[neighbor] = False

for i in range(1, N + 1):
    visited[i] = True
    dfs(i, 1)
    visited[i] = False
    if cnt > 0:
        break
if cnt > 0:
    print(1)
else:
    print(0)
    