import sys
from queue import PriorityQueue
sys.setrecursionlimit(100000)
V, E = map(int, sys.stdin.readline().split())
edges = []
parents = [i for i in range(V + 1)]

def find(a):
    if parents[a] != a:
        parents[a] = find(parents[a])
    return parents[a]

def union(a, b):
    rootA = find(a)
    rootB = find(b)
    if rootA != rootB:
        parents[rootB] = rootA

pq = PriorityQueue()
for _ in range(E):
    u, v, w = map(int, sys.stdin.readline().split())
    pq.put((w, u, v))

cnt = 0
minCost = 0

while cnt != V - 1:
    w, u, v = pq.get()
    if find(u) != find(v):
        union(u, v)
        minCost += w
        cnt += 1

print(minCost)