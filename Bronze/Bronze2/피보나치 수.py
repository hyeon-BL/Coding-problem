import sys
N = int(sys.stdin.readline())
if (N == 1):
	print(1)
	sys.exit()
dp = [0] * N
dp[0] = 1
dp[1] = 1
for i in range(2, N):
	dp[i] = dp[i - 2] + dp[i - 1]
print(dp[N - 1])
