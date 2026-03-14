import sys
N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
lis = []
lis_len = [0] * N


def binary_search(l, r, cur):
    while l < r:
        mid = (l + r) // 2
        if lis[mid] < cur:
            l = mid + 1
        else:
            r = mid
    return l

lis.append(A[0])
lis_len[0] = len(lis)
for i in range(1, N):
    if lis[-1] < A[i]:
        lis.append(A[i])
        lis_len[i] = len(lis)
    else:
        idx = binary_search(0, len(lis) - 1, A[i])
        lis[idx] = A[i]
        lis_len[i] = idx + 1

ans = []
print(len(lis))
for i in range(N - 1, -1, -1):
    if lis_len[i] == len(lis):
        ans.append(A[i])
        lis.pop()
print(" ".join(map(str, reversed(ans))))