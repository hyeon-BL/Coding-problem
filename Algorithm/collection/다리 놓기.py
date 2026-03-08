import sys
SIZE = 30
dp = [[0] * SIZE for _ in range(SIZE)]
for i in range(SIZE):
    dp[i][1] = i
    dp[i][0] = 1
    dp[i][i] = 1

for i in range(2, SIZE):
    for j in range(1, i):
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]

T = int(sys.stdin.readline())
for _ in range(T):
    N, M = map(int, sys.stdin.readline().split())
    print(dp[M][N])