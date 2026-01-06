import sys
sys.setrecursionlimit(100000)
N, M = map(int, sys.stdin.readline().split())
parent = [i for i in range(N + 1)]

def find(a):
    if parent[a] != a:
        parent[a] = find(parent[a])
    return parent[a]

def union(a, b):
    root_a = find(a)
    root_b = find(b)
    if parent[root_a] != parent[root_b]:
        parent[root_b] = root_a

edges = []
for _ in range(M):
    a, b, w = map(int, sys.stdin.readline().split())
    edges.append((w, a, b))
edges.sort(reverse=True)
start, to = map(int, sys.stdin.readline().split())

for w, a, b in edges:
    union(a, b)
    if find(start) == find(to):
        print(w)
        break