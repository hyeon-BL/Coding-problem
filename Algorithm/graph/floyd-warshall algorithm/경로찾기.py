import sys
N = int(sys.stdin.readline())
paths = [[] for _ in range(N)]

for i in range(N):
    row = list(map(int, sys.stdin.readline().split()))
    paths[i] = row

for K in range(N):
    for S in range(N):
        for E in range(N):
            if paths[S][E] == 0 and paths[S][K] == 1 and paths[K][E] == 1:
                paths[S][E] = 1

for row in paths:
    print(*row)