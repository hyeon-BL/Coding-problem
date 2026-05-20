import sys

T = int(sys.stdin.readline())
for _ in range(T):
	n, a, b = map(int, sys.stdin.readline().split())
	print(min(n * a, (n // 3) * b + (n % 3) * a, (n // 3 + 1) * b))
