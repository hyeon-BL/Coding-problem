import sys
N, M = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))

start, end = 0, 0
current_sum = 0
count = 0

# Two-pointer
while end < N:
    current_sum += A[end]
    end += 1

    while current_sum > M and start < end:
        current_sum -= A[start]
        start += 1

    if current_sum == M:
        count += 1

print(count)