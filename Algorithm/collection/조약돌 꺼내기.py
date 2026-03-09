import sys
M = int(sys.stdin.readline())
colors = list(map(int, sys.stdin.readline().split()))
K = int(sys.stdin.readline())
N = sum(colors)

dp = [[0] * (N + 1) for _ in range(N + 1)]
for i in range(N + 1):
    dp[i][1] = i
    dp[i][0] = 1
    dp[i][i] = 1

for i in range(2, N + 1):
    for j in range(1, i):
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]

each = 0
for num in colors:
    if num >= K:
        each += dp[num][K]
total = dp[N][K]
print(each / total)