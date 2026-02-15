import sys
import math
max_len = 10001
is_prime = [True] * max_len
for i in range(2, int(math.sqrt(max_len)) + 1):
    if is_prime[i]:
        for j in range(i + i, max_len, i):
            is_prime[j] = False 

T = int(sys.stdin.readline())
while T:
    n = int(sys.stdin.readline())

    for i in range(n // 2, n, 1):
        if is_prime[i] and is_prime[n - i]:
            print(n - i, i)
            break
    T -= 1
