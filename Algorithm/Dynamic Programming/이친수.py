# import sys
# N = int(sys.stdin.readline())
# dp = [1] * (N + 1)
# for i in range(3, N + 1):
#     dp[i] = dp[i - 1] + dp[i - 2]
# print(dp[N])

import sys
N = int(sys.stdin.readline())
dp = [[0] * 2 for _ in range(N + 1)]
dp[1][1] = 1 # 1자리, 1인 경우
dp[1][0] = 0 # 1자리, 0인 경우

for i in range(2, N + 1):
    dp[i][0] = dp[i - 1][1] + dp[i - 1][0]
    dp[i][1] = dp[i - 1][0]
print(dp[N][0] + dp[N][1])