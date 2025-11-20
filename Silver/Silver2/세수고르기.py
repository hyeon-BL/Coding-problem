import sys
N, M = map(int, sys.stdin.readline().split())
S = list(map(int, sys.stdin.readline().split()))
min_diff = float('inf')
for i in range(1, 1002):
    if i in S:
        continue
    for j in range(i, 1002):
        if j in S:
            continue
        for k in range(j, 1002):
            if k in S:
                continue
            diff = N - i * j * k
            if abs(diff) < min_diff:
                min_diff = abs(diff)
            if diff <= 0:
                break
print(min_diff)