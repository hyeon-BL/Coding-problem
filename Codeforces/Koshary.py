import sys
t = int(sys.stdin.readline())
for _ in range(t):
	x, y = map(int, sys.stdin.readline().split())
	print("YES" if (x % 2) + (y % 2) < 2 else "NO")
