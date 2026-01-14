import sys
N = int(sys.stdin.readline())
tree = [[] for _ in range(N)]
visited = [False] * N
leafCnt = 0
p = list(map(int, sys.stdin.readline().split()))

for i in range(N):
    if p[i] == -1:
        root = i
    else:
        tree[i].append(p[i])
        tree[p[i]].append(i)
removed = int(sys.stdin.readline())
childCnt = 0

def dfs(node):
    global removed, childCnt
    visited[node] = True
    child = 0
    for nxt in tree[node]:
        if not visited[nxt] and nxt != removed:
            dfs(nxt)
            child += 1
    if child == 0:
        childCnt += 1

dfs(root)
print(childCnt if root != removed else 0)