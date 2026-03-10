import sys
N = int(sys.stdin.readline())
dp = [0] * (N + 1)
MOD = 1000000000

if N >= 1: dp[1] = 0 # 혼자 교환 불가
if N >= 2: dp[2] = 1 # 서로 맞바꾸는 경우
for i in range(3, N + 1):
    dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]) % MOD

print(dp[N])




