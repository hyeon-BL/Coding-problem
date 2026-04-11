import sys
from queue import PriorityQueue
T = int(sys.stdin.readline())
for _ in range(T):
    n, d, c = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(n + 1)]
    visited = [False] * (n + 1)
    distances = [float('inf')] * (n + 1)

    for _ in range(d):
        a, b, s = map(int, sys.stdin.readline().split())
        graph[b].append((a, s))

    pq = PriorityQueue()
    distances[c] = 0
    pq.put((distances[c], c))


    while pq.qsize() > 0:
        time, cur = pq.get()
        if visited[cur]:
            continue
        visited[cur] = True
        for nxt, dt in graph[cur]:
            if not visited[nxt] and distances[nxt] > time + dt:
                distances[nxt] = time + dt
                pq.put((distances[nxt], nxt))
    
    infect_cnt = 0
    last_t = 0 
    for i in range(1, n + 1):
        if visited[i]:
            infect_cnt += 1
            last_t = max(last_t, distances[i])
    print(infect_cnt, last_t)