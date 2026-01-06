import sys
N, M = map(int, sys.stdin.readline().split())
parent = [i for i in range(N + 1)]

# find 연산
def find(a):
    if parent[a] == a:
        return a
    else:
        parent[a] = find(parent[a])
        return parent[a]
    
# union 연산
def union(a, b):
    a = find(a)
    b = find(b)
    if a != b:
        parent[b] = a

for _ in range(M):
    que, a, b = map(int, sys.stdin.readline().split())
    if que:
        if (find(a) == find(b)):
            print("YES")
        else:
            print("NO")
    else:
        union(a, b)