import sys
n = int(sys.stdin.readline())

dp = [0] * 10005
dp[1] = 1 # 1
dp[2] = 2 # 1 + 1, 2
dp[3] = 3 # 1 + 1 + 1, 1 + 2, 3
for i in range(4, 10005):
    dp[i] = dp[i - 3] + i // 2 + 1

for _ in range(n):
    target = int(sys.stdin.readline())
    print(dp[target])