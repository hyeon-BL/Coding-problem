import sys
from collections import deque
input = sys.stdin.readline
N = int(input())
K = int(input())
grid = [[0] * (N + 1) for _ in range(N + 1)]
for _ in range(K):
    r, c = map(int, input().split())
    grid[r][c] = 2 # 사과
L = int(input())
changes = {}
for _ in range(L):
    dur, pos = input().split()
    changes[int(dur)] = pos

T = 0
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
dq = deque()
dq.append((1, 1))
grid[1][1] = 1
r, c = 1, 1
d = 1
while True:
    T += 1

    nxt_r, nxt_c = r + directions[d][0], c + directions[d][1]
    if not (1 <= nxt_r <= N) or not (1 <= nxt_c <= N) or grid[nxt_r][nxt_c] == 1:
        break
    dq.appendleft((nxt_r, nxt_c))

    pr, pc = dq.pop() # 꼬리
    if grid[nxt_r][nxt_c] == 2:
        dq.append((pr, pc))
    else:
        grid[pr][pc] = 0
    grid[nxt_r][nxt_c] = 1

    r, c = nxt_r, nxt_c

    if T in changes.keys():
        if changes[T] == 'L':
            d = (d - 1) % 4
        elif changes[T] == 'D':
            d = (d + 1) % 4
print(T)