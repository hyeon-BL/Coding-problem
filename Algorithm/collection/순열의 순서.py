import sys
import math
N = int(sys.stdin.readline())
num, *arr = list(map(int, sys.stdin.readline().split()))
is_used = [False] * (N + 1)
seq = []

if num == 1:
    K = arr[0]
    for i in range(1, N + 1):
        cnt = 1
        for j in range(1, N + 1):
            if is_used[j]:
                continue
            if K <= cnt * math.factorial(N - i):
                K -= (cnt - 1) * math.factorial(N - i)
                seq.append(j)
                is_used[j] = True
                break
            cnt += 1
    print(" ".join(map(str, seq)))

else:
    K = 1
    for i in range(N):
        cnt = 0
        for j in range(1, arr[i]):
            if not is_used[j]:
                cnt += 1
        K += cnt * math.factorial(N - i - 1)
        is_used[arr[i]] = True
    print(K)
