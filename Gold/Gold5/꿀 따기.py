import sys
N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
cum = [arr[0]]
for i in range(1, N):
    cum.append(cum[-1] + arr[i])

res = 0
# 양 끝에서 오는 경우
for i in range(1, N - 1):
    temp = 0
    temp += cum[i] - cum[0]
    temp += cum[N - 1] - cum[i - 1] - arr[N - 1]
    res = max(res, temp)

# 왼쪽 끝에서 오는 경우
for i in range(1, N - 1):
    res = max(res, 2 * cum[N - 1] - cum[i - 1] - arr[0] - arr[i] * 2)

# 오른쪽 끝에서 오는 경우
for i in range(N - 2, 0, -1):
    res = max(res, cum[N - 1] + cum[i] - arr[N - 1] - arr[i] * 2)

print(res)