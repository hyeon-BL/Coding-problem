import sys
N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
A.sort()

start, end = 0, N - 1
count = 0

# Two-pointer
while start < end:
    current_sum = A[start] + A[end]

    if current_sum == M:
        count += 1
        start += 1
        end -= 1
    elif current_sum < M:
        start += 1
    else:
        end -= 1
print(count)