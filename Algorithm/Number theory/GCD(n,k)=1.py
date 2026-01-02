import sys
import math
N = int(sys.stdin.readline())

res = N
for i in range(2, int(math.sqrt(N) + 1)):
    if N % i == 0:
        res = res - (res // i)
        while N % i == 0:
            N /= i

if N > 1:
    res = res - (res // N)
print(int(res))