import sys

N, M = map(int, sys.stdin.readline().split())  # N : 정점 수, M : 간선 수

# Read edges
edges = []
for _ in range(M):
    a, b, c = map(int, sys.stdin.readline().split())
    edges.append((c, a, b))  # (weight, node1, node2)

# Union-Find data structure for Kruskal's algorithm with path compression and union by rank
parent = list(range(N+1))
rank = [0] * (N+1)

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])  # Path compression
    return parent[x]

def union(a, b):
    rootA, rootB = find(a), find(b)
    if rootA != rootB:
        if rank[rootA] > rank[rootB]:
            parent[rootB] = rootA
        elif rank[rootA] < rank[rootB]:
            parent[rootA] = rootB
        else:
            parent[rootB] = rootA
            rank[rootA] += 1

# Sort edges by weight
edges.sort()

# Kruskal's algorithm
mst_weight = 0
used_edges = 0
result = []

for weight, u, v in edges:
    if find(u) != find(v):
        union(u, v)
        mst_weight += weight
        used_edges += 1
        result.append((u, v))
        # All nodes connected
        if used_edges == N - 1:  # N - 1 edges are needed to connect N nodes
            break

print(mst_weight)