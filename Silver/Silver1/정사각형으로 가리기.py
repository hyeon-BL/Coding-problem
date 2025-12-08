import sys
N = int(sys.stdin.readline().rstrip())

min_x = float('inf')
max_x = float('-inf')
min_y = float('inf')
max_y = float('-inf')

dots = []
for _ in range(N):
    x, y = map(int, sys.stdin.readline().rstrip().split())
    dots.append((x, y))
    min_x = min(min_x, x)
    max_x = max(max_x, x)
    min_y = min(min_y, y)
    max_y = max(max_y, y)


length = max(max_y - min_y, max_x - min_x)
cnt1, cnt2 = 0, 0
for x, y in dots:
    if x == min_x or x == min_x + length:
        if (min_y <= y <= min_y + length):
            cnt1 += 1
    elif y == min_y or y == min_y + length:
        if (min_x <= x <= min_x + length):
            cnt1 += 1
    if x == max_x or x == max_x - length:
        if (max_y - length <= y <= max_y):
            cnt2 += 1
    elif y == max_y or y == max_y - length:
        if (max_x - length <= x <= max_x):
            cnt2 += 1
if cnt1 == N or cnt2 == N:
    print(length)
else:
    print(-1)