import sys
from queue import PriorityQueue
directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]
cnt = 1
while True:
    N = int(sys.stdin.readline())
    if N == 0:
        break
    grid = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
    distances = [[float('inf')] * N for _ in range(N)]
    visited = [[False] * N for _ in range(N)]
    
    pq = PriorityQueue()
    start = (0, 0); end = (N - 1, N - 1)
    distances[start[0]][start[1]] = grid[start[0]][start[1]]
    pq.put((distances[start[0]][start[1]], start))
    
    while pq.qsize() > 0:
        cum, cur = pq.get()

        if visited[cur[0]][cur[1]]:
            continue
        visited[cur[0]][cur[1]] = True

        for dir in directions:
            nxt_r = dir[0] + cur[0]
            nxt_c = dir[1] + cur[1]
            if 0 <= nxt_r <= N - 1 and 0 <= nxt_c <= N - 1 and not visited[nxt_r][nxt_c] and cum + grid[nxt_r][nxt_c] < distances[nxt_r][nxt_c]:
                distances[nxt_r][nxt_c] = cum + grid[nxt_r][nxt_c]
                pq.put((distances[nxt_r][nxt_c], (nxt_r, nxt_c)))
    
    print('Problem ', cnt, ': ', distances[end[0]][end[1]], sep='')
    cnt += 1