import sys
N = int(sys.stdin.readline())
arr = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]
dp = [[-1] * N for _ in range(N)]

def solve(s, e):
    result = float('inf')
    if dp[s][e] != -1:
        return dp[s][e]
    if s - e == 0:
        return 0
    if s - e == 1:
        return arr[s][0] * arr[s][1] * arr[e][1]
    for i in range(s, e):
        result = min(result, arr[s][0] * arr[i][1] * arr[e][1] + solve(s, i) + solve(i + 1, e))
    dp[s][e] = result
    return dp[s][e]

print(solve(0, N - 1))