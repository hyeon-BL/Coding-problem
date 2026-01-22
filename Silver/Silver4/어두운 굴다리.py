import sys
N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
positions = list(map(int, sys.stdin.readline().split()))

diff = -1
for i in range(M - 1):
    diff = max(diff, positions[i + 1] - positions[i])
dist = diff // 2 if diff % 2 == 0 else diff // 2 + 1
dist = max(dist, positions[0] - 0)
dist = max(dist, N - positions[M - 1])    

print(dist)