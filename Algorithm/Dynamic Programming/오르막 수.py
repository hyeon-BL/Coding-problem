import sys
N = int(sys.stdin.readline())
dp = [1] * 10
for _ in range(2, N + 1):
	for d in range(1, 10):
		dp[d] += dp[d - 1]
		dp[d] %= 10007
print(sum(dp) % 10007)
