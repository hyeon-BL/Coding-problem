import sys
N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
L = arr.copy()
R = arr.copy()

for i in range(1, N):
    L[i] = max(arr[i], L[i - 1] + arr[i])

for i in range(N - 2, -1, -1):
    R[i] = max(arr[i], R[i + 1] + arr[i])

res = max(L)
for i in range(1, N - 1):
    res = max(res, L[i - 1] + R[i + 1])
print(res)