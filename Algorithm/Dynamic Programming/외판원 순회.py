import sys
N = int(sys.stdin.readline())
W = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

dp = [[0] * (1 << N) for _ in range(N)]

def tsp(cur, visited):
    if visited == (1 << N) - 1:
        if W[cur][0] == 0:
            return float('inf')
        else:
            return W[cur][0]
    if dp[cur][visited]: # dfs + 이미 가본 경로 저장(memoization) -> ref: https://celbeing.tistory.com/176   
        return dp[cur][visited]
    res = float('inf')
    for i in range(N):
        if (1 << i & visited) == 0 and W[cur][i] != 0:
            res = min(res, tsp(i, (visited | 1 << i)) + W[cur][i])
    dp[cur][visited] = res
    return dp[cur][visited]

print(tsp(0, 1))