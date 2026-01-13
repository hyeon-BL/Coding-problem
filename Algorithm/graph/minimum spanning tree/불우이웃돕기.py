import sys
from queue import PriorityQueue
sys.setrecursionlimit(100000)
N = int(sys.stdin.readline())
edges = PriorityQueue()
parents = [i for i in range(N + 1)]
totalLen = 0
for i in range(N):
    row = sys.stdin.readline()
    for j in range(N):
        if row[j] == '0':
            continue
        else:
            leng = ord(row[j]) - ord('a') + 1 if row[j].islower() else ord(row[j]) - ord('A') + 27
            edges.put((leng, i + 1, j + 1))
            totalLen += leng

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
minLen = 0
while cc < N - 1 and not edges.empty():
    w, u, v = edges.get()
    if find(u) != find(v):
        union(u, v)
        minLen += w
        cc += 1

if cc != N - 1:
    print(-1)
else:
    print(totalLen - minLen)