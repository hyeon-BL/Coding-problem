import sys
from collections import deque
N = int(sys.stdin.readline())
tree = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    u, v = map(int, sys.stdin.readline().split())
    tree[u].append(v)
    tree[v].append(u)

depth = [0] * (N + 1)
parent = [0] * (N + 1)
visited = [False] * (N + 1)

def bfs(node):
    dq = deque()
    dq.append(node)
    visited[node] = True
    level = 1
    cur_size = 1
    cnt = 0
    while dq:
        cur = dq.popleft()
        for nxt in tree[cur]:
            if not visited[nxt]:
                dq.append(nxt)
                visited[nxt] = True
                parent[nxt] = cur
                depth[nxt] = level
        cnt += 1
        if cnt == cur_size:
            cnt = 0
            cur_size = len(dq)
            level += 1

def execLCA(a, b):
    if depth[a] < depth[b]: # 더 깊은 노드를 a에 저장
        temp = a
        a = b
        b = temp

    while depth[a] != depth[b]: # depth 통일
        a = parent[a]

    while a != b: # ancestor 찾기
        a = parent[a]
        b = parent[b]
    
    return a

bfs(1)
M = int(sys.stdin.readline())
for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    print(execLCA(a, b))