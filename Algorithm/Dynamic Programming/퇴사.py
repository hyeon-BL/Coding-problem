import sys
N = int(sys.stdin.readline())
T = [0] * (N + 1)
P = [0] * (N + 1)
dp = [0] * (N + 2)
for i in range(1, N + 1):
    T[i], P[i] = map(int, sys.stdin.readline().split())

for i in range(N, 0, -1):
    if i + T[i] > N + 1:
        dp[i] = dp[i + 1]
    else:
        dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i])
print(dp[1])