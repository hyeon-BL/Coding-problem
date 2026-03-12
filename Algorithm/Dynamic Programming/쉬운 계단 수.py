import sys
N = int(sys.stdin.readline())
dp = [[0] * 10 for _ in range(N + 1)] # dp[N][H]: 길이가 N이고, 맨 마지막이 H
MOD = 1000000000

# dp 초기화
for i in range(1, 10):
    dp[1][i] = 1 # 길이가 1이고 맨 마지막이 1 ~ 9인 경우 1개

# dp 업데이트
for i in range(2, N + 1):
    dp[i][0] = dp[i - 1][1]
    dp[i][9] = dp[i - 1][8]
    for j in range(1, 9):
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD

print(sum(dp[N]) % MOD)