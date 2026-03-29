import sys
import bisect
N, H = map(int, sys.stdin.readline().split())
top = []
bottom = []
for _ in range(N // 2):
    bottom.append(int(sys.stdin.readline()))
    top.append(int(sys.stdin.readline()))
bottom.sort()
top.sort()
min_val = float('inf')
cnt = 0
for i in range(H):
    bottom_lower = bisect.bisect_right(bottom, i)
    top_lower = bisect.bisect_left(top, H - i)
    val = N - bottom_lower - top_lower
    if min_val > val:
        min_val = val
        cnt = 1
    elif min_val == val:
        cnt += 1
print(min_val, cnt)
