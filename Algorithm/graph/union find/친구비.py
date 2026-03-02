import sys
sys.setrecursionlimit(10**5)
N, M, k = map(int, sys.stdin.readline().split())
costs = list(map(int, sys.stdin.readline().split()))
sortedCosts = [(costs[i], i + 1) for i in range(N)]
sortedCosts.sort()
parents = [i for i in range(N + 1)]

def find(a):
    if parents[a] != a:
        parents[a] = find(parents[a])
    return parents[a]

def union(a, b):
    rootA = find(a)
    rootB = find(b)
    if rootA != rootB:
        parents[rootB] = rootA

totalCost = 0
for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    union(u, v)
for cost, i in sortedCosts:
    if find(0) != find(i):
        totalCost += cost
        union(0, i)

if totalCost > k:
    print("Oh no")
else:
    print(totalCost)