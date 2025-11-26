import sys
from math import gcd
from collections import defaultdict

N = int(sys.stdin.readline())
comb = [list(map(int, sys.stdin.readline().split())) for _ in range(N - 1)]

# Graph representation
graph = defaultdict(list)
for a, b, p, q in comb:
    graph[a].append((b, p, q))
    graph[b].append((a, q, p))

# store value as fraction num/den relative to root 0
num = [0] * N
den = [0] * N
visited = [False] * N

def dfs(u):
    visited[u] = True
    for v, p, q in graph[u]:
        if not visited[v]:
            # u / v = p / q  =>  v = u * q / p
            num[v] = num[u] * q
            den[v] = den[u] * p
            g = gcd(num[v], den[v])
            num[v] //= g
            den[v] //= g
            dfs(v)

num[0], den[0] = 1, 1
dfs(0)

def lcm(a, b):
    return a // gcd(a, b) * b

l = 1
for d in den:
    l = lcm(l, d)

arr = [num[i] * (l // den[i]) for i in range(N)]

g_all = 0
for v in arr:
    g_all = gcd(g_all, v)
arr = [v // g_all for v in arr]

print(" ".join(map(str, arr)))