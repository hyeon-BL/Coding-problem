import sys
N, M = map(int, sys.stdin.readline().split())
arr = [list(sys.stdin.readline().strip()) for _ in range(N)]

# sorted list of edges by priority
edges = []
for i in range(N):
    for j in range(i + 1, N):
        if arr[i][j] == 'Y':
            edges.append((i, j))

total = len(edges)
# necessary checks
if M < N - 1 or M > total:
    print(-1)
    sys.exit()

class DSU:
    def __init__(self, n):
        self.p = list(range(n))
    def find(self, x):
        while self.p[x] != x:
            self.p[x] = self.p[self.p[x]]
            x = self.p[x]
        return x
    def union(self, a, b):
        ra, rb = self.find(a), self.find(b)
        if ra == rb:
            return False
        if ra < rb:
            self.p[rb] = ra
        else:
            self.p[ra] = rb
        return True

dsu = DSU(N)
deg = [0] * N
mst_edges = 0
leftover = []

for u, v in edges:
    if mst_edges == N - 1:
        leftover.append((u, v))
        continue
    if dsu.union(u, v):
        deg[u] += 1
        deg[v] += 1
        mst_edges += 1
    else:
        leftover.append((u, v))

if mst_edges != N - 1:
    print(-1)
    sys.exit()

need_extra = M - (N - 1)
if need_extra > len(leftover):
    print(-1)
    sys.exit()

for i in range(need_extra):
    a, b = leftover[i]
    deg[a] += 1
    deg[b] += 1

print(" ".join(map(str, deg)))
