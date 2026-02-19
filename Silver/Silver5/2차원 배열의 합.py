import sys
N, M = map(int, sys.stdin.readline().split())
cumulative = [[] for _ in range(N)]

for i in range(N):
    row = list(map(int, sys.stdin.readline().split()))
    s = 0
    for e in row:
        cumulative[i].append(s)
        s += e
    cumulative[i].append(s)
    

K = int(sys.stdin.readline())
for _ in range(K):
    i, j, x, y = map(int, sys.stdin.readline().split())
    cul = 0
    for r in range(i - 1, x):
        cul += cumulative[r][y] - cumulative[r][j - 1]
    print(cul)