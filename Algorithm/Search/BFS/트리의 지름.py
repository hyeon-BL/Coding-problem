import sys
from collections import deque

N = int(sys.stdin.readline())
graph = [[] for _ in range(N + 1)]
for _ in range(N):
    inp = list(map(int, sys.stdin.readline().split()))
    node = inp[0]
    next_index = 1
    while (inp[next_index] != -1):
        graph[node].append((inp[next_index], inp[next_index+1])) # (next_node, length)
        next_index += 2

distances = [-1 for _ in range(N + 1)]

def bfs(start):
    q = deque()
    q.append(start)
    distances[start] = 0

    while q:
        cur = q.popleft()
        for next, leng in graph[cur]:
            if distances[next] == -1:
                q.append(next)
                distances[next] = distances[cur] + leng

# first bfs
bfs(1)
new_start = 1
for i in range(N + 1):
    if distances[i] > distances[new_start]:
        new_start = i

# second bfs
distances = [-1 for _ in range(N + 1)]
bfs(new_start)
distances.sort()
print(distances[N])