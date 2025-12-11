import sys

s = sys.stdin.readline().rstrip()

dp = [[-1] * (len(s) + 1) for _ in range(len(s) + 1)]

def solve(l, r, temp):
    global dp
    if dp[l][r] != -1:
        return dp[l][r]
    if l >= r:
        return 0
    ret = solve(l + 1, r - 1, temp) + (0 if temp[l] == temp[r] else 1) # 다르면 문자 교체, 같으면 그대로
    ret = min(ret, solve(l + 1, r, temp) + 1) # 왼쪽 문자 삭제(=오른쪽 삽입)
    ret = min(ret, solve(l, r - 1, temp) + 1) # 오른쪽 문자 삭제(=왼쪽 삽입)
    dp[l][r] = ret
    return ret

ans = solve(0, len(s) - 1, s)
for i in range(len(s)):
    for j in range(i + 1, len(s)):
        dp = [[-1] * (len(s) + 1) for _ in range(len(s) + 1)]
        tem = s[:i] + s[j] + s[i + 1:j] + s[i] + s[j + 1:] # i, j 위치 문자 교환
        ans = min(ans, solve(0, len(s) - 1, tem) + 1)

print(ans)