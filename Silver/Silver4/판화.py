import sys
N = int(sys.stdin.readline())
trace = [[[False, False] for _ in range(N)] for _ in range(N)]
dir = {'D': (1, 0), 'U': (-1, 0), 'R': (0, 1), 'L': (0, -1)}

moves = sys.stdin.readline().rstrip()

i, j = 0, 0
for m in moves:
    d = dir.get(m)
    ni, nj = i + d[0], j + d[1]
    if 0 <= ni < N and 0 <= nj < N:
        if m in 'UD':
            trace[i][j][0] = True
            trace[ni][nj][0] = True
        else:
            trace[i][j][1] = True
            trace[ni][nj][1] = True
        i, j = ni, nj

for i in range(N):
    row = []
    for j in range(N):
        if trace[i][j][0] == trace[i][j][1] == True:
            row.append('+')
        elif trace[i][j][0]:
            row.append('|')
        elif trace[i][j][1]:
            row.append('-')
        else:
            row.append('.')
    print(''.join(row))