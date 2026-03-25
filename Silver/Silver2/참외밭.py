import sys
K = int(sys.stdin.readline())
square = [tuple(map(int, sys.stdin.readline().split())) for _ in range(6)]

max_w, max_h = 0, 0
for i in range(6):
    if square[i][0] == 1 or square[i][0] == 2:
        max_w = max(square[i][1], max_w)
    else:
        max_h = max(square[i][1], max_h)
square.extend(square)
while (square[0][1] != max_w and square[0][1] != max_h) or (square[1][1] != max_w and square[1][1] != max_h):
    del square[0]
sub_sqare = square[3][1] * square[4][1]
print((max_w * max_h - sub_sqare) * K)