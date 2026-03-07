import sys
from collections import deque
N = int(sys.stdin.readline())
tree = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    u, v = map(int, sys.stdin.readline().split())
    tree[u].append(v)
    tree[v].append(u)

depth = [0] * (N + 1)
visited = [False] * (N + 1)
k_max = 0
while (1 << k_max) <= N:
    k_max += 1
parent = [[0] * (N + 1) for _ in range(k_max + 1)]

def bfs(node):
    dq = deque()
    dq.append((node, 0))
    visited[node] = True
    while dq:
        cur, level = dq.popleft()
        for nxt in tree[cur]:
            if not visited[nxt]:
                visited[nxt] = True
                dq.append((nxt, level + 1))
                depth[nxt] = level + 1
                parent[0][nxt] = cur

def execLCA(a, b):
    if depth[a] < depth[b]: # 더 깊은 노드를 a에 저장
        temp = a
        a = b
        b = temp

    for k in range(k_max, -1, -1): # depth 통일
        if pow(2, k) <= depth[a] - depth[b]: # -> 2^k만큼 한번에 이동
            if depth[b] <= depth[parent[k][a]]:
                a = parent[k][a]

    for k in range(k_max, -1, -1): # ancestor 찾기
        if a == b: break
        if parent[k][a] != parent[k][b]:
            a = parent[k][a]
            b = parent[k][b]

    res = a
    if a != b:
        res = parent[0][res]
    return res

bfs(1)
for k in range(1, k_max + 1):
    for n in range(1, N + 1):
        parent[k][n] = parent[k - 1][parent[k - 1][n]]
M = int(sys.stdin.readline())
for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    print(execLCA(a, b))