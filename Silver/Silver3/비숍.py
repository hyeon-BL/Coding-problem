import sys
N = int(sys.stdin.readline().rstrip())

if N <= 2:
    print(N)
else:
    print(N + N - 2)