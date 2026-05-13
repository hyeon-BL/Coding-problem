import sys
from itertools import combinations

def gcd(x, y):
	if y == 0:
		return x
	return gcd(y, x % y)

T = int(sys.stdin.readline())
for _ in range(T):
	N = int(sys.stdin.readline())
	arr = list(map(int, sys.stdin.readline().split()))

	cnt = 0
	for start in range(N - 1):
		x, y = arr[start], arr[start + 1]
		if abs(x - y) == gcd(x, y):
			cnt += 1
	print(cnt)
