import sys
import math
Min, Max = map(int, sys.stdin.readline().split())
is_squared = [False for _ in range(Max - Min + 1)]

for i in range(2, int(math.sqrt(Max)+ 1)):
    square = pow(i, 2)
    start = Min // square if Min % square == 0 else Min // square + 1
    for j in range(start, Max // square + 1):
        is_squared[j * square - Min] = True

cnt = 0
for i in range(len(is_squared)):
    if not is_squared[i]:
        cnt += 1
print(cnt)