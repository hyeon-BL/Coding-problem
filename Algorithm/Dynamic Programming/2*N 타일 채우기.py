import sys
N = int(sys.stdin.readline())
dp = [1] * (N + 1)
for i in range(2, N + 1):
    dp[i] = (dp[i - 1] + dp[i - 2]) % 10007
print(dp[N])