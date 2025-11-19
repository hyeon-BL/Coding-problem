import sys
N, K = map(int, sys.stdin.readline().split())
quotient = N // K
remainder = N % K
nums = [quotient] * K
for i in range(remainder):
    nums[i] += 1
max_prod = 1
for num in nums:
    max_prod *= num
print(max_prod)