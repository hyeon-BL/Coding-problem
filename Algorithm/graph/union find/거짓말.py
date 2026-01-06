import sys
sys.setrecursionlimit(100000)
N, M = map(int, sys.stdin.readline().split())
truths = list(map(int, sys.stdin.readline().split()))[1:]
parent = [i for i in range(N + 1)]

def find(a):
    if parent[a] != a:
        parent[a] = find(parent[a])
    return parent[a]

def union(a, b):
    root_a = find(a)
    root_b = find(b)
    if root_a != root_b:
        parent[root_b] = root_a

party = [list(map(int, sys.stdin.readline().split())) for _ in range(M)]
for i in range(M):
    if party[i][0] != 1:
        for j in range(1, party[i][0]):
            union(party[i][j], party[i][j + 1])

cnt = 0
for i in range(M):
    representitive = party[i][1]
    for truth in truths:
        if find(representitive) == find(truth):
            break
    else:
        cnt += 1
print(cnt)
