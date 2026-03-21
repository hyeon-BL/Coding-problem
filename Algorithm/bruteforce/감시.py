import sys
N, M = map(int, sys.stdin.readline().split())
grid = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

DIRS = [(-1, 0), (0, 1), (1, 0), (0, -1)]

ORIENTS = {
    1: [[0], [1], [2], [3]],
    2: [[0, 2], [1, 3]],
    3: [[0, 1], [1, 2], [2, 3], [3, 0]],
    4: [[0, 1, 2], [1, 2, 3], [2, 3, 0], [3, 0, 1]],
    5: [[0, 1, 2, 3]]
}

cameras = []
zeros = 0
for i in range(N):
    for j in range(M):
        v = grid[i][j]
        if 1 <= v <= 5:
            cameras.append((i, j, v))
        elif v == 0:
            zeros += 1

visited = [[0] * M for _ in range(N)]  # 1이면 감시받는 영역
best = zeros
observed = 0

def apply_watch(i, j, dir_idx):
    dx, dy = DIRS[dir_idx]
    x, y = i + dx, j + dy
    changed = []
    while 0 <= x < N and 0 <= y < M and grid[x][y] != 6:
        if grid[x][y] == 0 and visited[x][y] == 0:
            visited[x][y] = 1
            changed.append((x, y))
        x += dx
        y += dy
    return changed

def backtrack(idx):
    global best, observed
    if idx == len(cameras):
        blind = zeros - observed
        if blind < best:
            best = blind
        return

    i, j, t = cameras[idx]
    for orient in ORIENTS[t]:
        total_changed = []
        for d in orient:
            changed = apply_watch(i, j, d)
            observed += len(changed)
            total_changed.extend(changed)

        backtrack(idx + 1)

        for (x, y) in total_changed:
            visited[x][y] = 0
        observed -= len(total_changed)

backtrack(0)
print(best)