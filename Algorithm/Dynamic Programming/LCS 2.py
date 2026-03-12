import sys
sys.setrecursionlimit(10000)
s1 = sys.stdin.readline().rstrip()
s2 = sys.stdin.readline().rstrip()
dp = [[0] * (len(s2) + 1) for i in range(len(s1) + 1)]
path = []

for i in range(1, len(s1) + 1):
    for j in range(1, len(s2) + 1):
        if s1[i - 1] == s2[j - 1]: # 현재 위치가 같음
            dp[i][j] = dp[i - 1][j - 1] + 1 # 이전 위치 값 + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

def getLCS(i, j):
    if i == 0 or j == 0:
        return
    if s1[i - 1] == s2[j - 1]:
        path.append(s1[i - 1])
        getLCS(i - 1, j - 1)
    else:
        if dp[i - 1][j] > dp[i][j - 1]:
            getLCS(i - 1, j)
        else:
            getLCS(i, j - 1)

getLCS(len(s1), len(s2))
print(dp[len(s1)][len(s2)])
print("".join(reversed(path)))