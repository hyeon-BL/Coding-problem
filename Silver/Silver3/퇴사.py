import sys
N = int(sys.stdin.readline())
consults = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]

dp = [0 for _ in range(N + 1)]

for i in range(N):
	for j in range(i + consults[i][0], N + 1):
		dp[j] = max(dp[j], dp[i] + consults[i][1])

print(dp[N])
