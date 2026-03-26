import sys
from collections import deque
T = int(sys.stdin.readline())

def bfs(node):
    dq = deque()
    dq.append((node, 0))
    visited[node] = 0
    while dq:
        cur, level = dq.popleft()
        for nxt in tree[cur]:
            if visited[nxt] == -1:
                dq.append((nxt, level + 1))
                visited[nxt] = level + 1
                parent[nxt] = cur

def execLCA(a, b):
    if visited[a] < visited[b]: # 더 깊은 노드를 a에 저장
        temp = a
        a = b
        b = temp

    while visited[a] != visited[b]: # depth 통일
        a = parent[a]

    while a != b: # ancestor 찾기
        a = parent[a]
        b = parent[b]
    
    return a

for _ in range(T):
    N = int(sys.stdin.readline())
    visited = [-1] * (N + 1)
    parent = [-1] * (N + 1)
    tree = [[] for _ in range(N + 1)]
    root = (1 << N + 1) - 1
    for _ in range(N - 1):
        p, q = map(int, sys.stdin.readline().split())
        tree[p].append(q)
        if root & (1 << q):
            root &= ~(1 << q)
    cnt = 1
    while (root & (1 << cnt)) == 0:
        cnt += 1
    bfs(cnt)
    s, e = map(int, sys.stdin.readline().split())
    print(execLCA(s, e))