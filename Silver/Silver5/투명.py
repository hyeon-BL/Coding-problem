import sys
N, M = map(int, sys.stdin.readline().split())

mask = [[0] * 100 for _ in range(100)]
for _ in range(N):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    for i in range(x1 - 1, x2):
        for j in range(y1 - 1, y2):
            mask[i][j] += 1


count = 0
for i in range(100):
    for j in range(100):
        if mask[i][j] > M:
            count += 1
print(count)