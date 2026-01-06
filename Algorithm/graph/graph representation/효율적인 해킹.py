import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
adj = [[] for _ in range(N + 1)]
ans = [0] * (N + 1)

def bfs(node):
    dq = deque()
    dq.append(node)
    visited[node] = True
    while dq:
        cur = dq.popleft()
        for next in adj[cur]:
            if not visited[next]:
                visited[next] = True
                dq.append(next)
                ans[next] += 1

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    adj[u].append(v)

for s in range(1, N + 1):
    visited = [False] * (N + 1)
    bfs(s)

max_val = max(ans)
for i in range(1, N + 1):
    if ans[i] == max_val:
        print(i, end=' ')


''' Python DFS 시간초과 (too deep)
import sys
sys.setrecursionlimit(10000)

N, M = map(int, sys.stdin.readline().split())
adj = [[] for _ in range(N + 1)]
ans = [0] * (N + 1)
memo = [-1] * (N + 1)

def dfs(node):
    visited[node] = 1
    count = 1  # 자기 자신 포함
    for next in adj[node]:
        if not visited[next]:
            count += dfs(next)
    memo[node] = count  # 결과 저장
    return count

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    adj[v].append(u)

for s in range(1, N + 1):
    visited = [0] * (N + 1)
    ans[s] = dfs(s)

max_val = max(ans)
for i in range(1, N + 1):
    if ans[i] == max_val:
        print(i, end=' ')

'''