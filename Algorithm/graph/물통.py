import sys
from collections import deque
volumes = tuple(map(int, sys.stdin.readline().split()))
case = [(0, 1), (0, 2), (1, 0), (1, 2), (2, 0), (2, 1)]
visited = [[[False] * 201 for i in range(201)] for j in range(201)]
ans = []

dq = deque()
dq.append((0, 0, volumes[2]))
visited[0][0][volumes[2]] = True
ans.append(volumes[2])
while dq:
    cur = dq.popleft()
    for frm, to in case:
        nxt = list(cur)
        if nxt[frm] + nxt[to] <= volumes[to]: 
            nxt[to] += nxt[frm]
            nxt[frm] = 0
        else:
            nxt[frm] -= (volumes[to] - nxt[to])
            nxt[to] = volumes[to]
        if not visited[nxt[0]][nxt[1]][nxt[2]]:
            dq.append(nxt)
            visited[nxt[0]][nxt[1]][nxt[2]] = True
            if nxt[0] == 0:
                ans.append(nxt[2])

ans.sort()
print(*ans) # Unpacking 