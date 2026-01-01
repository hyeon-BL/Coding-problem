import sys
import math
A, B = map(int, sys.stdin.readline().split())

max_ran = 10000001  # 10^7
is_primes = [True for _ in range(max_ran)]
for i in range(2, int(math.sqrt(max_ran)) + 1):
    if is_primes[i]:
        for j in range(i + i, max_ran, i):
            is_primes[j] = False

cnt = 0
for i in range(2, max_ran):
    if is_primes[i]:
        almost_prime = i
        while almost_prime <= B:
            almost_prime *= i
            if A <= almost_prime <= B:
                cnt += 1
    if i > B:
        break
print(cnt)
