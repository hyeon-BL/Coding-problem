import sys
from collections import deque
initial = ""
for i in range(3):
    row = sys.stdin.readline().split()
    for e in row:
        initial += e

cases = {}
cases[initial] = 0
dq = deque()
dq.append(initial)
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def swap(cur, pos1, pos2):
    res_lst = list(cur)
    res_lst[pos1], res_lst[pos2] = res_lst[pos2], res_lst[pos1]
    res = ''.join(res_lst)
    return res

while dq:
    cur = dq.popleft()

    idx_0 = cur.index('0')
    x = idx_0 // 3
    y = idx_0 % 3
    for dx, dy in directions:
        nx = x + dx
        ny = y + dy

        if (0 <= nx < 3 and 0 <= ny < 3):
            nxt = swap(cur, x * 3 + y, nx * 3 + ny)

            if nxt not in cases:
                cases[nxt] = cases[cur] + 1
                dq.append(nxt)

if "123456780" not in cases:
    print(-1)
else:
    print(cases["123456780"])