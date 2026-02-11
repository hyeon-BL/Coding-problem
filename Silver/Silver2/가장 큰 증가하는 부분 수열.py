import sys
N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

dp = arr.copy()
max_sum = arr[0]
for i in range(1, N):
	for j in range(0, i):
		if arr[i] > arr[j]:
			dp[i] = max(dp[i], dp[j] + arr[i])
	max_sum = max(max_sum, dp[i])
print(max_sum)
