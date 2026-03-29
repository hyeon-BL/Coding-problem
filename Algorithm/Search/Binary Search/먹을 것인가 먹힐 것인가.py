import sys
T = int(sys.stdin.readline())

def upper(size, t):
    s = 0
    e = size - 1
    while (s < e):
        m = (s + e) // 2
        if A[m] <= t:
            s = m + 1
        else:
            e = m
    if A[e] <= t:
        return 0
    return size - e


for _ in range(T):
    lenA, lenB = map(int, sys.stdin.readline().split())
    A = list(map(int, sys.stdin.readline().split()))
    B = list(map(int, sys.stdin.readline().split()))
    A.sort()
    cnt = 0
    for ele in B:
        cnt += upper(lenA, ele)
    print(cnt)