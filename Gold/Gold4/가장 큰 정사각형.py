import sys
N, M = map(int, sys.stdin.readline().split())
arr = [[0] * (M + 1) for _ in range(N + 1)]
DP = [[0] * (M + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
	row = sys.stdin.readline().strip()
	for j in range(1, M + 1):
		arr[i][j] = int(row[j - 1])

max_len = 0
for i in range(1, N + 1):
	for j in range(1, M + 1):
		if arr[i][j] == 1:
			DP[i][j] = min(DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]) + 1
			max_len = max(max_len, DP[i][j])

print(max_len ** 2)
