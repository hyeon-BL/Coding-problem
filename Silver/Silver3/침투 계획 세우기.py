import sys
x, y = map(int, sys.stdin.readline().split())

if x == 0 and y == 0:
    print(1)
    sys.exit()

z = -x - y
k = max(abs(x), abs(y), abs(z)) # k is the layer number
start = 3 * k * (k - 1) + 2 # start number of layer k

cx, cy = k - 1, 1 # starting coordinates
idx = start
if cx == x and cy == y:
    print(idx)
    sys.exit()
directions = [(-1, 1), (-1, 0), (0, -1), (1, -1), (1, 0), (0, 1)]   
for d in directions:
    for _ in range(k):
        cx += d[0]
        cy += d[1]
        idx += 1
        if cx == x and cy == y:
            print(idx)
            sys.exit()