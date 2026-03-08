import sys
N, K = map(int, sys.stdin.readline().split())
dp = [[0] * (N + 1) for _ in range(N + 1)]

# DP 초기화
for i in range(1, N + 1):
    dp[i][1] = i # i개 중 1개 선택
    dp[i][0] = 1 # i개 중 0개 선택
    dp[i][i] = 1 # i개 중 i개 선택

for i in range(2, N + 1):
    for j in range(1, i):
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]

print(dp[N][K])