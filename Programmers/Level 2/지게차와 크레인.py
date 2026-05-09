from collections import deque

def bfs(grid, req):
    n = len(grid)
    m = len(grid[0])
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    visited = [[False] * m for _ in range(n)]
    picks = []    

    start = (0, 0)
    dq = deque()
    dq.append(start)
    visited[start[0]][start[1]] = True
    while dq:
        cr, cc = dq.popleft()

        for dr, dc in directions:
            nr, nc = cr + dr, cc + dc
            if 0 <= nr < n and 0 <= nc < m and not visited[nr][nc] and grid[nr][nc] == '0':
                dq.append((nr, nc))
                visited[nr][nc] = True
            elif 0 <= nr < n and 0 <= nc < m and grid[nr][nc] == req:
                picks.append((nr, nc))
    return picks

def bruteforce(grid, req):
    n = len(grid)
    m = len(grid[0])
    picks = []
    for i in range(n):
        for j in range(m):
            if grid[i][j] == req[0]:
                picks.append((i, j))
    return picks

def solution(storage, requests):
    answer = 0

    grid = []
    grid.append(['0'] * (len(storage[0]) + 2))
    for row in storage:
        grid.append(['0'] + list(row) + ['0'])
    grid.append(['0'] * (len(storage[0]) + 2))
    for req in requests:
        if len(req) == 1:
            picks = bfs(grid, req)
        else:
            picks = bruteforce(grid, req)
        for pick in picks:
            grid[pick[0]][pick[1]] = '0'
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] != '0':
                answer += 1
    return answer

print(solution(["AZWQY", "CAABX", "BBDDA", "ACACA"], ["A", "BB", "A"]))