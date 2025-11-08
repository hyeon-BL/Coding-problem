import sys
N, D = map(int, sys.stdin.readline().split())
roads = []

for _ in range(N):
    roads.append(tuple(map(int, sys.stdin.readline().split())))

roads.sort()
dp = [i for i in range(D + 1)]
idx = 0
for i in range(0, D + 1):
    dp[i] = min(dp[i], dp[i - 1] + 1)
    while idx < N and roads[idx][0] == i:
        start, end, length = roads[idx]
        if end <= D:
            dp[end] = min(dp[end], dp[start] + length)
        idx += 1
print(dp[D])