import sys
N, K = map(int, sys.stdin.readline().split())
A = [int(sys.stdin.readline()) for _ in range(N)]

min_needed = 0
target_sum = K
for coin in reversed(A):
    if coin <= target_sum:
        min_needed += target_sum // coin
        target_sum = target_sum % coin

    if target_sum == 0:
        break

print(min_needed)  

