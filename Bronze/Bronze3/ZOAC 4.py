import sys
H, W, N, M = map(int, sys.stdin.readline().split())

row = H // (N + 1) if H % (N + 1) == 0 else H // (N + 1) + 1
column = W // (M + 1) if W % (M + 1) == 0 else W // (M + 1) + 1
print(row * column)