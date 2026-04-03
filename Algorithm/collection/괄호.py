import sys
dp = [0] * 2501
dp[0] = 1
for i in range(1, 2501):
    s = 0
    for j in range(i):
        s += dp[j] * dp[i-1-j]
        s %= 1000000007
    dp[i] = s


T = int(sys.stdin.readline())
for _ in range(T):
    L = int(sys.stdin.readline())
    if L % 2 == 0:
        print(dp[L // 2])
    else:
        print(0)