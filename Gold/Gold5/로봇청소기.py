import sys
N, M = map(int, sys.stdin.readline().split())
r, c, d = map(int, sys.stdin.readline().split())
grid = [[] for _ in range(N)]
for i in range(N):
    grid[i] = list(sys.stdin.readline().split())

dir = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def check_neighbor(r, c):
    for dr, dc in dir:
        nr, nc = dr + r, dc + c
        if 0 <= nr < N - 1 and 0 <= nc < M:
            if grid[nr][nc] == '0':
                return True
    else:
        return False
    
def move_back(r, c, d):
    nr, nc = r - dir[d][0], c - dir[d][1]
    if 0 <= nr < N - 1 and 0 <= nc < M and grid[nr][nc] != '1':
        return (nr, nc)
    else:
        return (-1, -1)
    
def move_forward(r, c):
    global d
    for _ in range(4):
        d = (d + 3) % 4
        nr, nc = r + dir[d][0], c + dir[d][1]
        if 0 <= nr < N - 1 and 0 <= nc < M and grid[nr][nc] == '0':
            return nr, nc
    return (-1, -1)

cnt = 0
while True:
    if grid[r][c] == '0':
        cnt += 1
        grid[r][c] = str(cnt + 2)

    if not check_neighbor(r, c):
        r, c = move_back(r, c, d)
        if (r == -1 and c == -1):
            break
        else:
            continue
    else:
        r, c = move_forward(r, c)
        if (r == -1 and c == -1):
            continue
print(cnt)
# for i in range(N):
#     print(''.join([f'{item:<{3}}' for item in grid[i]]))

