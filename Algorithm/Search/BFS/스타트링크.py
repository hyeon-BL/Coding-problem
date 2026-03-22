import sys
from collections import deque
F, S, G, U, D = map(int, sys.stdin.readline().split())
visited = [False] * (F + 1)

cnt = 0
dq = deque()
visited[S] = True
dq.append((S, cnt))

while dq:
    cur_l, cur_c = dq.popleft()

    if cur_l == G:
        print(cur_c)
        break

    nxt_u = cur_l + U
    nxt_d = cur_l - D
    if nxt_u <= F and not visited[nxt_u]:
        visited[nxt_u] = True
        dq.append((nxt_u, cur_c + 1))
    if nxt_d > 0 and not visited[nxt_d]:
        visited[nxt_d] = True
        dq.append((nxt_d, cur_c + 1))
else:
    print("use the stairs")