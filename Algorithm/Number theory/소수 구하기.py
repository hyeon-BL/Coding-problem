import sys
import math
N, M = map(int, sys.stdin.readline().split())

nums = [True for _ in range(M + 1)]
for i in range(2, int(math.sqrt(M) + 1)):
    if nums[i]:
        for j in range(2 * i, M + 1, i):
            nums[j] = False

for i in range(N, M + 1):
    if i == 1:
        continue
    if nums[i]:
        print(i)