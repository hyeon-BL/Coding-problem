import sys
R, C = map(int, sys.stdin.readline().split())
rows = []
for _ in range(R):
    row = sys.stdin.readline().rstrip()
    rows.append(row)

dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]
for i in range(R):
    for j in range(C):
        if rows[i][j] == 'S':
            for dr, dc in dir:
                nr = i + dr
                nc = j + dc
                if 0 <= nr < R and 0 <= nc < C:
                    if rows[nr][nc] == 'W':
                        print(0)
                        sys.exit()
print(1)
for i in range(R):
    for j in range(C):
        if rows[i][j] == '.':
            print('D', end='')
        else:
            print(rows[i][j], end='')
    print()