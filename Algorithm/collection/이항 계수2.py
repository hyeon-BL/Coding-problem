import sys
N, K = map(int, sys.stdin.readline().split())
dp = [[0] * (N + 1) for _ in range(N + 1)]
MOD = 10007
for i in range(1, N + 1):
    dp[i][1] = i
    dp[i][0] = 1
    dp[i][i] = 1

for i in range(2, N + 1):
    for j in range(1, i):
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD

print(dp[N][K])