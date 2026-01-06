import sys
sys.setrecursionlimit(100000)
N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
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

for i in range(N):
    connected = list(map(int, sys.stdin.readline().split()))
    for j in range(N):
        if connected[j]:
            union(i+1, j+1)

travel_path = list(map(int, sys.stdin.readline().split()))
representitive = find(travel_path[0])
for city in travel_path:
    if find(city) != representitive:
        print("NO")
        break
else:
    print("YES")