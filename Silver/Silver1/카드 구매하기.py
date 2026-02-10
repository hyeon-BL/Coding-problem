import sys
N = int(sys.stdin.readline())
arr = [0] + list(map(int, sys.stdin.readline().split()))

dp = [0] * (N + 1) # dp[i]: i개 구매했을 때 비용의 최댓값
dp[1] = arr[1]
for i in range(2, N + 1):
	for j in range(1, i + 1):
		dp[i] = max(dp[i], dp[i - j] + arr[j]) # i개 구매했을 때 j개 구매 포함 or not
print(dp[N])
