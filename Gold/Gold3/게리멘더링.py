import sys
from itertools import combinations

N = int(sys.stdin.readline())
populations = [0] + list(map(int, sys.stdin.readline().split()))
graph = [[] for _ in range(N + 1)]

for i in range(1, N + 1):
    arr = list(map(int, sys.stdin.readline().split()))
    graph[i] = arr[1:]

def dfs(cur, s):
    visited[cur] = True
    total = s
    for nxt in graph[cur]:
        if not visited[nxt]:
            total += dfs(nxt, populations[nxt])
    return total

res = float('inf')
for k in range(1, N // 2 + 1):
    for teamA in combinations(range(1, N + 1), k):
        teamB = tuple(set(range(1, N + 1)) - set(teamA))
        visited = [True] + [False if i in teamA else True for i in range(1, N + 1)]
        sumA = dfs(teamA[0], populations[teamA[0]])
        if sum(visited) != N + 1: continue
        visited = [True] + [False if i in teamB else True for i in range(1, N + 1)]
        sumB = dfs(teamB[0], populations[teamB[0]])
        if sum(visited) != N + 1: continue
        
        if sumA != -1 and sumB != -1:
            res = min(res, abs(sumA - sumB))

print(res) if res != float('inf') else print(-1)
