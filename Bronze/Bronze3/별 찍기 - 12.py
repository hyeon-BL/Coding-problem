import sys
N = int(sys.stdin.readline())
for i in range(-(N - 1), N):
	print(" " * abs(i) + "*" * (N - abs(i)))
