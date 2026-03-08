import sys
SIZE = 15
dp = [[0] * SIZE for _ in range(SIZE)]
for i in range(SIZE):
    dp[0][i] = i # 0층에는 i명 거주

for i in range(1, SIZE): # 층
    for j in range(1, SIZE): # 호
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j]

T = int(sys.stdin.readline())
for _ in range(T):
    floor = int(sys.stdin.readline())
    num = int(sys.stdin.readline())
    print(dp[floor][num])