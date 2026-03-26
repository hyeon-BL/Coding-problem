import sys
N, M = map(int, sys.stdin.readline().split())
sys.setrecursionlimit(10**5)
tree = [[] for _ in range(N + 1)]

for i in range(N - 1):
    p, q, d = map(int, sys.stdin.readline().split())
    tree[p].append((q, d))
    tree[q].append((p, d))

def dfs(s, e):
    global distance
    visited[s] = True
    if s == e:
        return True
    for nxt, d in tree[s]:
        if not visited[nxt]:
            distance += d
            found = dfs(nxt, e)
            if found:
                return True
            distance -= d
    return False

for _ in range(M):
    distance = 0
    visited = [False] * (N + 1)
    s, e = map(int, sys.stdin.readline().split())
    dfs(s, e)
    print(distance)