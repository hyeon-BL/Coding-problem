import sys
from queue import PriorityQueue
sys.setrecursionlimit(100000)

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
edges = PriorityQueue()
parents = [i for i in range(N + 1)]

for _ in range(M):
    u, v, w = map(int, sys.stdin.readline().split())
    edges.put((w, u, v))

def find(a):
    if parents[a] != a:
        parents[a] = find(parents[a])
    return parents[a]

def union(a, b):
    rootA = find(a)
    rootB = find(b)
    if rootA != rootB:
        parents[rootB] = rootA

cc = 0
minCost = 0

while cc < N - 1:
    w, u, v = edges.get()
    if find(u) != find(v):
        union(u, v)
        minCost += w
        cc += 1

print(minCost)