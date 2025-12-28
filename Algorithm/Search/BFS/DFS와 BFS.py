import sys
from collections import deque
sys.setrecursionlimit(10000)

N, M, S = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

for i in range(N + 1):
    graph[i].sort()

visited_dfs = [False] * (N + 1)
visited_bfs = [False] * (N + 1)

def dfs(node):
    visited_dfs[node] = True
    print(node, end=' ')
    for next in graph[node]:
        if not visited_dfs[next]:
            dfs(next)

def bfs(node):
    q = deque()
    q.append(node)
    visited_bfs[node] = True

    while(q):
        cur = q.popleft()
        print(cur, end=' ')
        for next in graph[cur]:
            if not visited_bfs[next]:
                q.append(next)
                visited_bfs[next] = True

dfs(S)
print()
bfs(S)

