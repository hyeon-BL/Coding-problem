import sys
from collections import deque
L, W = map(int, sys.stdin.readline().split())
grid = [sys.stdin.readline().rstrip() for _ in range(L)]
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def bfs(r, c):
    visited = [[False] * W for _ in range(L)]
    dq = deque()
    dq.append((r, c, 0))

    visited[r][c] = True
    max_dist = 0
    while dq:
        cur_r, cur_c, cur_l = dq.popleft()
        max_dist = max(max_dist, cur_l)

        for dr, dc in directions:
            nxt_r, nxt_c = cur_r + dr, cur_c + dc

            if 0 <= nxt_r < L and 0 <= nxt_c < W and grid[nxt_r][nxt_c] == 'L' and not visited[nxt_r][nxt_c]:
                dq.append((nxt_r, nxt_c, cur_l + 1))
                visited[nxt_r][nxt_c] = True
    return max_dist

max_s = 0
for r in range(L):
    for c in range(W):
        if grid[r][c] == 'L':
            max_s = max(max_s, bfs(r, c))
print(max_s)