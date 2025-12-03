import sys
N = int(sys.stdin.readline())
L = list(map(int, sys.stdin.readline().split()))
J = list(map(int, sys.stdin.readline().split()))
dp = [[0] * 101 for _ in range(N + 1)] # dp[i][j]: i번째 사람, j의 체력일 때 최대 기쁨
for i in range(1, N + 1):
    for j in range(100, -1, -1):
        dp[i][j] = dp[i - 1][j]  # 인사 안함
        if j - L[i - 1] > 0:
            dp[i][j] = max(dp[i][j], dp[i - 1][j - L[i - 1]] + J[i - 1])  # 인사 함
print(max(dp[N]))   
