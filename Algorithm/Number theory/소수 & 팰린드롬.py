import sys
import math
N = int(sys.stdin.readline())

is_primes = [True for _ in range(10000001)] # 최대 범위
for i in range(2, int(math.sqrt(len(is_primes)) + 1)):
    if is_primes[i]:
        for j in range(i * 2, len(is_primes), i):
            is_primes[j] = False
is_primes[1] = False

for i in range(N, len(is_primes)):
    if is_primes[i]:
        num = str(i)
        num_rev = num[::-1] # reversed
        if num == num_rev:
            print(i)
            break