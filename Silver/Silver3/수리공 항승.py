import sys
N, L = map(int, sys.stdin.readline().split())
regions = list(map(int, sys.stdin.readline().split()))
regions.sort()

count = 1
temp = regions[0]
for i in range(N - 1):
    if regions[i + 1] - temp < L:
        pass
    else:
        count += 1
        temp = regions[i + 1]
print(count)