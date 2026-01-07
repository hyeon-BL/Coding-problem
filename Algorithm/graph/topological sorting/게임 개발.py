import sys
from collections import deque
N = int(sys.stdin.readline())
graph = [[] for _ in range(N + 1)]
times = [0] * (N + 1)
indegree = [0] * (N + 1)
ans = [0] * (N + 1)

for i in range(1, N + 1):
    time, *nodes = map(int, sys.stdin.readline().split())
    times[i] = time
    nodes.pop() # -1 제거
    for node in nodes:
        graph[node].append(i)
        indegree[i] += 1

dq = deque()
for i in range(1, N + 1):
    if indegree[i] == 0:
        dq.append((i, times[i]))

while dq:
    cur, t = dq.popleft()
    ans[cur] = max(t, ans[cur])
    for nxt in graph[cur]:
        indegree[nxt] -= 1
        ans[nxt] = max(ans[nxt], ans[cur] + times[nxt])
        if indegree[nxt] == 0:
            dq.append((nxt, times[nxt]))

for i in range(1, N + 1):
    print(ans[i])

'''
서로 다른 가지에서 들어오는 edge의 경우 서로 독립적으로 작용(-> max를 사용해 다음 노드가 어떤 가지에 종속되는지 확인해야 함)


---
    \
     -----
    /
---

'''