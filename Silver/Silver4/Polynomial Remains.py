import sys
while True:
    n, k = map(int, sys.stdin.readline().split())
    if n == -1 and k == -1:
        break

    ax = list(map(int, sys.stdin.readline().split()))

    for i in range(n, k - 1, -1):
        ax[i - k] -= ax[i]

    if k == 0:
        print(0)
    else:
        print(' '.join(map(str, ax[:k])))
    