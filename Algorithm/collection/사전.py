import sys
N, M, K = map(int, sys.stdin.readline().split())
dp = [[0] * (N + M + 1) for _ in range(N + M + 1)]

for i in range(N + M + 1):
    dp[i][1] = i
    dp[i][0] = 1
    dp[i][i] = 1

for i in range(1, N + M + 1):
    for j in range(1, i):
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]

if dp[N + M][M] < K:
    print(-1)
else:
    while not (N == 0 and M == 0):
        if dp[N - 1 + M][M] >= K:
            print("a", end="")
            N -= 1
        else:
            print("z", end="")
            K -= dp[N - 1 + M][M]
            M -= 1