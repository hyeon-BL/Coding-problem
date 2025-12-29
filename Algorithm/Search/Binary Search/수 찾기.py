import sys
N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
A.sort()

M = int(sys.stdin.readline())
targets = list(map(int, sys.stdin.readline().split()))

for ele in targets:
    start = 0
    end = N - 1
    while start <= end:
        mid = (start + end) // 2
        if A[mid] > ele:
            end = mid - 1
        elif ele > A[mid]:
            start = mid + 1
        else:
            print(1)
            break
    else:
        print(0)