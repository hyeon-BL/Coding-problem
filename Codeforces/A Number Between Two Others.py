import sys
T = int(sys.stdin.readline())
for _ in range(T):
	x, y = map(int, sys.stdin.readline().split())
	for z in range(x, y, x):
		if y % z != 0:
			print("YES")
			break
	else:
		print("NO")
