import sys
T = int(sys.stdin.readline())
for _ in range(T):
    N = int(sys.stdin.readline())
    maxA = -1
    ans = -1
    for _ in range(N):
        S, L = sys.stdin.readline().split()
        if int(L) > maxA:
            maxA = int(L)
            ans = S
    else:
        print(ans)